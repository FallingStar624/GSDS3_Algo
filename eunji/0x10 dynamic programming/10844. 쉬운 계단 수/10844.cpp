/*
문제 : 
인접한 모든 자리의 차이가 1인 수를 계단 수라 함
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자
0으로 시작하는 수는 계단수가 아니다

Input : 
N (1보다 크고 100보다 작거나 작은 자연수)

Output : 
정답을 1,000,000,000으로 나눈 나머지를 출력
*/

#include <iostream>
#include <math.h>
using namespace std;

int N;
long long dp[102][12]; // 자리수 // 마지막 자리의 수 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    dp[1][0] = 0;
    for (int i=1; i<=9; i++){
      dp[1][i] = 1; 
    }

    for (int i=2; i<=N; i++){
      for (int j=0; j<=9; j++){
        if (j==0){
          dp[i][j] = dp[i-1][j+1] % 1000000000;
        }
        else if (j==9) {
          dp[i][j] = dp[i-1][j-1] % 1000000000;
        }
        else {
          dp[i][j] = dp[i-1][j-1] % 1000000000 + dp[i-1][j+1] % 1000000000;
        }
       
      }
    }

    long long answer = 0;
    for (int i=0; i<=9; i++){
      answer += dp[N][i] % 1000000000 ;
    }

    cout << answer % 1000000000 ;

    return 0;
}