#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    long long* arr;
    arr = (long long*)malloc(sizeof(long long)* N);
    for(int i=0; i<N; i++){
        long long  tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    sort(arr, arr+N);
    long long maxval = arr[0];
    int cnt = 1;
    int maxcnt = 1;
    for (int i = 1; i < N; i++){
        if(arr[i] == arr[i-1]) {
            cnt++;
            if ((i == N-1) && (cnt > maxcnt)){
                maxcnt = cnt;
                cnt = 1;
                maxval = arr[i-1];
            }
            else if ((i == N-1) && (cnt == maxcnt)){
                if (maxval > arr[i-1]){
                    maxcnt = cnt;
                    cnt = 1;
                    maxval = arr[i-1];
                }
            }
        }
        else if(cnt > maxcnt){
            maxcnt = cnt;
            cnt = 1;
            maxval = arr[i-1];
        }
        else if (cnt == maxcnt){
            if (maxval > arr[i-1]){
                maxcnt = cnt;
                cnt = 1;
                maxval = arr[i-1];
            }
            cnt = 1;
        }
        else{
            cnt = 1;
        }
    }
    cout << maxval;
}