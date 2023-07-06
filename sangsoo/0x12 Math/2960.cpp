#include <bits/stdc++.h>
using namespace std;

int arr[1002];
int N, K;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int cnt = 0;
    int m = 2;
    int start = 1;
    for (int i = 2 ; i < 1002; i++)
        arr[i] = 1;
    while(m <= N){
        start += 1;
        if (arr[start] == 0) continue;
        for (int i = start; i <= N; i+=m){
            if(arr[i] == 1){
                arr[i] = 0; cnt++;
                if(cnt == K){
                    cout << i ; return 0;
                }
            }
        }
        while(1){
            if(arr[m] == 0) {m++;}
            else break;
        }
    }
}