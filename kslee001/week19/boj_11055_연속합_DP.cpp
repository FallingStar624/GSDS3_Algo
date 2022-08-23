// https://www.acmicpc.net/problem/11055 연속합
#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >>n;
    for(int i=1; i<=n; ++i) cin >>arr[i];

    dp[1] = arr[1];
    dp[2] = max(dp[1] + arr[2], arr[2]);

    for(int i=3; i<=n; ++i){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }
    int res = -1000000000;
    for(int i=1; i<= n; ++i){
        if(dp[i] > res) res = dp[i];
    } 
    cout << res;
}