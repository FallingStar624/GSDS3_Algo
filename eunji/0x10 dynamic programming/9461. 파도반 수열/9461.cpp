/*
문제 : 
첫 정삼각형 변의 길이는 1임
나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가

Input : 
테스트 케이스의 개수 T
각 테스트 케이스의 N (1 ≤ N ≤ 100)

Output : 
수열 P(N) = 나선에 있는 정삼각형의 변의 길이
*/

#include <iostream>
using namespace std;

int N;
long long P[102];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;

    for (int i=0; i<N; i++){
        int input;
        cin >> input;
        for (int j=4; j<=input; j++){
            P[j] = P[j-2] + P[j-3];
        } 
        cout << P[input] << '\n';
    }

    return 0;
}