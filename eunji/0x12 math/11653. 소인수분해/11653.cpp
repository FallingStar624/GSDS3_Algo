/*
정수 N 소인수분해
input : 정수 N (1 ≤ N ≤ 10,000,000)
output : 한 줄에 하나씩 오름차순 (N=1이면 출력 없음)
*/

#include <iostream>
#include <math.h>
using namespace std;

int N;
void CheckDivision(int* num, int divider);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i=2; i<=N; ++i){
        if (N == 1) return 0;
        CheckDivision(&N, i);
    }

    return 0;
}

void CheckDivision(int* num, int divider){
    if (*num % divider == 0){
        cout << divider << '\n';
        *num = *num/divider;
        CheckDivision(num, divider);
    }
}
