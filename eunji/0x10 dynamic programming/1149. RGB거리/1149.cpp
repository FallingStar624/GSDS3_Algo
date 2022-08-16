/*
문제 : 
1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

Input : 
- 집의 수 N(2 ≤ N ≤ 1,000)
- 각 집을 빨강, 초록, 파랑으로 칠하는 비용 (<=1000)
Output : 첫째 줄에 모든 집을 칠하는 비용의 최솟값
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N;
int P[1002][3]; // 집별 0 빨, 1 초, 2 파 가격
int D[1002][3]; // 0 빨, 1 초, 2 파 선택

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> P[i][0] >> P[i][1] >> P[i][2];
    }

    for (int i=1; i<=N; i++){
        D[i][0] = min(D[i-1][1], D[i-1][2]) + P[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + P[i][1];
        D[i][2] = min(D[i-1][1], D[i-1][0]) + P[i][2];
    }

    cout << min(min(D[N][0], D[N][1]), D[N][2]);

    return 0;
}