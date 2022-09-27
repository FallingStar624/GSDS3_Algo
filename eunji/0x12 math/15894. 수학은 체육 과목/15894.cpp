/*
인풋: 가장 아랫부분의 정사각형 개수 n  (1 ≤ n ≤ 10^9)
형석이가 말해야 하는 답을 출력
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long  N;
long long answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    answer = N * 4;
    cout << answer;

    return 0;
}