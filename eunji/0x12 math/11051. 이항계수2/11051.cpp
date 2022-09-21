/*
자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K) 구하기
input : N, K (1 ≤ N ≤ 10, 0 ≤ K ≤ N)
nCk = n-1Ck + n-1Ck-1

*/

#include <iostream>
using namespace std;

int N, K;
int dp[1002][1002];


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for (int i=0; i<=N; ++i){
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i=2; i<=N; ++i){
        for (int j=0; j<=K; ++j){
            dp[i][j] = dp[i-1][j] %10007+ dp[i-1][j-1]%10007;
        }
    }

    cout << dp[N][K] %10007;

}