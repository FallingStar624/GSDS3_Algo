// 1st row: 1<=N<=500,000
// 2nd row: num, -10,000,000<= num <=10,000,000
// 3rd row: 1<=M<=500,000
// 4th row: X (same range)
// # of N =/= # of M

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500002];

int lidx(int num){ // num 최초 등장 위치 or (없으면) num보다 큰 수 최초 등장 위치
    int st = 0;
    int en = n;

    while(st<en){ // st = en : 원하는 idx 위치 (leftmost)
        int mid = (en-st)/2 + st;
        if(arr[mid]>=num) en = mid; // 뒤 범위 줄이고 다시 찾기
        else st = mid+1;
    }
    return st; // or en
}

int uidx(int num){ // num보다 큰 수 최초 등장 위치
    int st = 0;
    int en = n;

    while(st<en){ // st = en : rightmost idx
        int mid = (en-st)/2 + st;
        if(arr[mid]>num) en=mid;
        else st = mid+1;
    }
    return st;

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    cin>>m;

    int tmp;
    while(m--){
        cin>>tmp;
        cout<< uidx(tmp)-lidx(tmp) << ' ';
    }
    return 0;

}

// freq index return
// # of steps keeping ascending order
// en에 주의 -> en = mid