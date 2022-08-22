/*
문제 : 
아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램

Input : 
삼각형의 크기 n(1 ≤ n ≤ 500)
n+1번째 줄까지 정수 삼각형 (0~9999)

Output : 
합이 최대가 되는 경로에 있는 수의 합
*/

#include <algorithm>
#include <iostream>
using namespace std;

int n; 
int d[502][502]; // 해당 줄에서의 각 칸마다의 최대값
int t[502][502]; // 삼각형 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
      for (int j=0; j<i+1; j++){
        cin >> t[i][j];
      }
    }

    d[0][0] = t[0][0];

    for (int i=1; i<502; i++){
      for (int j=0; j<502; j++){
        if (j==0){
          d[i][0] = d[i-1][0] + t[i][0];
        }
        else if (j==i){
          d[i][j] = d[i-1][j-1] + t[i][j];
        }
        else {
          d[i][j] = max(d[i-1][j-1], d[i-1][j]) + t[i][j];
        }
      }
    }

    int answer = 0;
    for (int i=0; i<n; i++){
      if (d[n][i] > answer) answer = d[n][i];
    }
    cout << answer;   

    return 0;
}