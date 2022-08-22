/*
문제 : 
2×n 크기의 직사각형을 1×2, 2×1, 2x2 타일로 채우는 방법의 수를 구하는 프로그램

Input : n (1 ≤ n ≤ 1,000)
Output : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int D[1002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    D[1] = 1;
    D[2] = 3;

    for (int i=3; i<=N; i++){
        D[i] = (D[i-1] + 2*D[i-2])%10007;
    }

    cout << D[N] ;
}