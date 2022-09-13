/*
문제 : 
남은 N일 동안 최대한 많은 상담을 함
각각의 상담은 상담을 완료하는데 걸리는 기간 Ti, 상담을 했을 때 받을 수 있는 금액 Pi

Input : 
N (1 ≤ N ≤ 15)
Ti와 Pi가 공백으로 구분 (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

Output : 백준이가 얻을 수 있는 최대 이익
*/

#include <iostream>
using namespace std;

int N;

typedef struct{
    int duration;
    int profit;
} consult;
consult c[18]; 

int dp[18]; // max profit for each day

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> c[i].duration >> c[i].profit;
    }

    for (int i=1; i<=N; i++){
        if (N - i + 1 >= c[i].duration){
            dp[i] += c[i].profit;
            int temp = 0;
            for (int j=i; j>=1; j--){
                if (j+c[j].duration <= i && temp < dp[j]){
                    temp = dp[j];
                }
            }
            dp[i] += temp;
        }
        else if (N - i + 1 < c[1].duration){
            dp[i] = 0;
        }
    }

    // for (int i=0; i<=N; i++){
    //     cout << dp[i] << '\n';
    // }

    int answer = 0;
    for (int i=0; i<=N; i++){
        if (answer < dp[i]) answer = dp[i];
    }
    cout << answer;

    return 0;
}