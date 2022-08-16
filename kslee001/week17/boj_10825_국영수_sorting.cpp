// https://www.acmicpc.net/problem/10825 국영수
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
struct student{
    int korean;
    int english;
    int math;
    string name;
    student(){
        korean = 0;
        english = 0;
        math = 0;
        name ="";
    }
    student(int a, int b, int c, string d){
        korean = a;
        english = b;
        math = c;
        name = d;
        }
};

// struct 담아놓을 arr
student arr[100000];
// 정렬용 arr
student sorted[100000];

void init(){
    cin >>n;
    for(int i=0; i<n; ++i){
        string name; int k, e, m;
        cin >>name >> k >> e >> m;
        arr[i] = student(k, e, m, name);
    }
}

void merge(student* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        // 1. korean 비교
        if(arr[i].korean > arr[j].korean) 
            sorted[k++] = arr[i++];
        else if(arr[i].korean < arr[j].korean)
            sorted[k++] = arr[j++];
        // 2. english 비교
        else{
            if(arr[i].english < arr[j].english)
                sorted[k++] = arr[i++];
            else if(arr[i].english > arr[j].english)
                sorted[k++] = arr[j++];
            // 3. math 비교
            else{
                if(arr[i].math > arr[j].math)
                    sorted[k++] = arr[i++];
                else if (arr[i].math < arr[j].math)
                    sorted[k++] = arr[j++];
                else{
                    int str_size = arr[i].name.size();
                    bool flag = false;
                    for(int idx=0; idx < arr[i].name.size() && idx < arr[j].name.size(); ++idx){
                        char c1 = arr[i].name[idx];
                        char c2 = arr[j].name[idx];
                        if(c1 == c2) continue;
                        if(c1 < c2){
                            flag = true;
                            sorted[k++] = arr[i++];
                            break;
                        }
                        if(c1 > c2){
                            flag = true;
                            sorted[k++] = arr[j++];
                            break;
                        }
                    } 
                    if(!flag){
                        if(arr[i].name.size() < arr[j].name.size())
                            sorted[k++] = arr[i++];
                        else
                            sorted[k++] = arr[j++];
                    }
                }
            }
        }
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(student* arr, int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}


int main(){
    init();
    msort(arr, 0, n-1);
    for(int i=0; i<n-1; ++i){
        cout << arr[i].name << "\n";
    }
    cout << arr[n-1].name;

}
