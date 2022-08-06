// https://www.acmicpc.net/problem/2910 빈도정렬

#include <iostream>
#include <map>
#include <queue>
using namespace std;

int n, k;
map<int,int> count;
map<int,int> order;
int number[1000];

struct pw{
    int val;
    int order;
    int cnt;
    pw(){val=0;order=0;cnt=0;};
    pw(int a, int b, int c){
        val = a;
        order = b;
        cnt = c;
    }
};

pw arr[1000];
pw sorted[1000];

void merge(pw* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        // count 순서로 정렬
        if(arr[i].cnt > arr[j].cnt) 
            sorted[k++] = arr[i++];
        else if(arr[i].cnt < arr[j].cnt)
            sorted[k++] = arr[j++];
        // count가 같은 경우, order순서로 정렬
        else{
            if(arr[i].order < arr[j].order)
                sorted[k++] = arr[i++];
            else
                sorted[k++] = arr[j++];
        }
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(pw* arr, int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n >> k;
    int input;
    int idx = 0; // 등장한 순서
    for(int i=0; i<n; ++i){
        cin >>input;
        if(!order[input]){ // 1. 처음 등장한 경우
            order[input] = idx+1;    // 등장 순서 표시
            count[input] = 1;      // 카운트 1
            number[idx++] = input; // 무슨 수였는지 표시 
        }
        else{
            ++count[input];    // 2. 이미 등장했던 경우 카운트++
        }
    }

    // array에 입력
    for(int i=0; i<idx; ++i){
        int cur_val = number[i];
        int cur_order = order[cur_val];
        int cur_cnt = count[cur_val];
        arr[i] = pw(cur_val, cur_order, cur_cnt);
    }    
    
    // sorting
    msort(arr, 0, idx-1);

    // printing
    for(int i=0; i<idx; ++i){
        for(int j=0; j<count[arr[i].val]; ++j)
            cout << arr[i].val << " ";
    }
}


