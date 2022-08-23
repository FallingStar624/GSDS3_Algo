/*
문제 : 
임의의 수열에서 연속된 몇 개의 수를 선택해서 
구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
단, 수는 한 개 이상 선택

Input : 
정수 n(1 ≤ n ≤ 100,000)
n개의 정수로 이루어진 수열 (-1,000~1,000)

Output : N자리 이친수의 개수
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int input[100002];
int sum[100002]; // 각 칸이 마지막 숫자일 때 최대값

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
      cin >> input[i];
    }

    sum[0] = input[0];

    for (int i=0; i<N; i++){
      if (input[i] < sum[i-1] + input[i]) {
        sum[i] = sum[i-1] + input[i];
      }
      else sum[i] = input[i];
    }

    int answer = -1000;

    for (int i=0; i<N; i++){
      if (answer < sum[i]) answer = sum[i];
    }

    cout << answer;

    return 0;

}