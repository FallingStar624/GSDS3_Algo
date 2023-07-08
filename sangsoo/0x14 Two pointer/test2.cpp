#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[4];
int st, en;
int mn;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    N = 4; M = 5;
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 10;
    st = 0; en = 0; mn = 2e9+1;
    sort(arr, arr+N);
    while(st < N){
        while(en < N){
            if(arr[en] - arr[st] >= M&& arr[en] - arr[st] < mn){
                mn = arr[en]-arr[st];
                break;
            }
            else
                en++;
        }
        st++;
    }
    cout << mn;
    return 0;
}
