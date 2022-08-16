/*
문제 : 
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.

Input : 
1보다 크거나 같고, 106보다 작거나 같은 자연수 N

Output : 
첫째 줄에 연산을 하는 횟수의 최솟값
둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력
정답이 여러 가지인 경우에는 아무거나 출력
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int D[1000002]; // 연산 최소 횟수
int M[1000002]; // 연산 방법
vector<int> v; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++){
        if (i == 1) { 
            D[i] = 0; 
            M[i] = 1;
            continue;
        }
        D[i] = D[i-1]+1;
        M[i] = i-1;
        if (i % 3 == 0 && D[i] > D[i/3]+1){
            D[i] = D[i/3]+1;
            M[i] = i/3;
        }
        if (i % 2 == 0 && D[i] > D[i/2]+1){
            D[i] = D[i/2]+1;
            M[i] = i/2;
        }
    }

    // for (int i=1; i<=N; i++){
    //     cout << i << ' ' << M[i] << '\n';
    // }

    cout << D[N] << '\n';
    cout << N << ' ';

    int count = N;
    while (count > 1){
        cout << M[count] << ' ';
        count = M[count];
    }

    return 0;
}