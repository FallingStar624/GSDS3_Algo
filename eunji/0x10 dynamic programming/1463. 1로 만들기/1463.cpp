/*
문제 : 
1. 3으로 나누어 떨어지면 3으로 나누기
2. 2로 나누어 떨어지면 2로 나누기
3. 1을 빼기
1을 만들기 위한 연산 횟수 최솟값

Input : N (1<=N<=10^6)
Output : 연산 횟수 최솟값 
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N;
int D[1000002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++){
        if (i == 1) { D[i] = 0; continue;}
        if (i % 3 == 0 && i % 2 == 0){
            D[i] = min(min(D[i/3]+1, D[i/2]+1), D[i-1]+1);
        }
        else if (i % 3 != 0 && i % 2 == 0){
            D[i] = min(D[i/2]+1, D[i-1]+1);
        }
        else if (i % 3 == 0 && i % 2 != 0){
            D[i] = min(D[i/3]+1, D[i-1]+1);
        }
        else if (i % 3 != 0 && i % 2 != 0){
            D[i] = D[i-1] + 1;
        }
    }

    cout << D[N];
}