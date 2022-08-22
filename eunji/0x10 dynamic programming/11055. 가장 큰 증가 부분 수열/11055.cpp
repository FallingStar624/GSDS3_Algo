/*
문제 : 
수열의 증가 부분 수열 중에서 합이 가장 큰 것

Input : 
수열 A의 크기 N (1 ≤ N ≤ 1,000)
수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output : 수열 A의 합이 가장 큰 증가 부분 수열의 합
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int input[1002];
int sum[1002]; // 각 칸이 마지막 숫자일 때 최대값

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
      cin >> input[i];
    }

    sum[0] = input[0];

    for (int i=1; i<N; i++){
      if (input[i-1] < input[i] && input[i] < sum[i-1] + input[i]) {
        sum[i] = input[i];
        int temp = 0;
        for (int j=i-1; j>=0; j--){
          if (input[j] < input[i] && temp < sum[j]){
            sum[i] = input[i] + sum[j];
            temp = sum[j];
          }
        }
      }
      else if (input[i-1] >= input[i]){
        sum[i] = input[i];
        int temp = 0;
        for (int j=i-1; j>=0; j--){
          if (input[j] < input[i] && temp < sum[j]){
            sum[i] = input[i] + sum[j];
            temp = sum[j];
          }
        }
      }
      else sum[i] = input[i];
    }

    // for (int i=0; i<N; i++){
    //   cout << sum[i] << ' ' ;
    // }
    // cout << '\n';

    int answer = -1000;

    for (int i=0; i<N; i++){
      if (answer < sum[i]) answer = sum[i];
    }

    cout << answer;

    return 0;
}