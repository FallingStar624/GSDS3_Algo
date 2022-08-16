/*
문제 : 
계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값 구하기

Input : 
- 계단 개수 (<=300)
- 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수 (<=10000)
Output : 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N;
int stairs[302];
int D[302][3]; // 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을때 최댓값

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> stairs[i];
    }

    D[1][1] = stairs[1];
    D[1][2] = 0;
    D[2][1] = stairs[2];
    D[2][2] = stairs[2] + stairs[1];

    for (int i=3; i<=N; i++){
        D[i][1] = max(D[i-2][1], D[i-2][2]) + stairs[i];
        D[i][2] = D[i-1][1] + stairs[i];
    }

    cout << max(D[N][1], D[N][2]);
    return 0;
}
