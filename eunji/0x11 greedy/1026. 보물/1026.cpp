/*
문제 : 
길이가 N인 정수 배열 A와 B
S = A[0] × B[0] + ... + A[N-1] × B[N-1]
S의 값을 가장 작게 만들기 위해 A의 수를 재배열
단, B에 있는 수는 재배열하면 안 된다.

Input : 
N(첫째 줄)은 50보다 작거나 같은 자연수
A(둘째 줄)와 B(셋째 줄)의 각 원소는 100보다 작거나 같은 음이 아닌 정수

Output : 
S의 최솟값
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N; 
int A[52];
int B[52];
int answer = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N ;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+N);

    for (int i=0; i<N; i++){
        answer += A[i]*B[N-i-1];
    }

    cout << answer;

    return 0;
}