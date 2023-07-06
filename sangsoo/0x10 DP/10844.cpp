#include <bits/stdc++.h>
using namespace std;
/*
dp[i][j] : 길이 i인 계단에 j로 끝나는 마지막 계단의 수
이전 길이가 무엇으로 끝나냐에 영향을 받음.
*/
long long dp[102][12];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 101; i++){
        for(int j = 0; j < 10; j++){
            if (j == 0) dp[i][j] = dp[i-1][j+1]%1000000000;
            else if (j == 9) dp[i][j] = dp[i-1][j-1]%1000000000;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < 10; i++){
        sum += dp[n][i];
    }
    cout << sum%1000000000 ;
}