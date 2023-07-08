#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, st, en, partialsum;
int arr[10002];
int psumarr[10002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    //prefix sum array
    psumarr[0] = arr[0];
    for(int i = 1; i < N; i++) psumarr[i] = arr[i]+psumarr[i-1];
    while(st < N){
        while(en < N){
            partialsum = (st > 0) ? psumarr[en] - psumarr[st-1] : psumarr[en];
            if(partialsum == M){
                cnt++;
                st++;en++;
            }
            else if (partialsum > M) break;
            else en++;
        }
        st++;
    }
    cout << cnt;
}