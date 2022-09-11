/*
문제 : 
남은 N일 동안 최대한 많은 상담을 함
각각의 상담은 상담을 완료하는데 걸리는 기간 Ti, 상담을 했을 때 받을 수 있는 금액 Pi

Input : 
N (1 ≤ N ≤ 1,500,000)
Ti와 Pi가 공백으로 구분 (1 ≤ Ti ≤ 50, 1 ≤ Pi ≤ 1,000)

Output : 백준이가 얻을 수 있는 최대 이익
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;

typedef struct{
    int duration;
    int profit;
} consult;
consult c[1500002]; 

int dp[1500002]; // max profit for each day

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> c[i].duration >> c[i].profit;
    }

    for (int i=N; i>=1; i--){
        if (N - i + 1 >= c[i].duration){
            dp[i] = max(dp[i+1], c[i].profit + dp[c[i].duration + i]);
        }
        else if (N - i + 1 < c[i].duration){
            dp[i] = dp[i+1];
        }
    }

    // for (int i=0; i<=N; i++){
    //     cout << dp[i] << '\n';
    // }

    cout << dp[1];

    return 0;
}