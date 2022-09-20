/*
M이상 N이하의 소수를 모두 출력
M이상 N이하의 소수가 하나 이상 있는 입력만 주어짐

input : M N (1 ≤ M ≤ N ≤ 1,000,000) 
*/

#include <iostream>
#include <math.h>
using namespace std;

int M;
int N;
int IsPrime(int num);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;

    for (int i=M; i<=N; ++i){
        if (IsPrime(i)) {
            cout << i << '\n';
        }
    }

    return 0;
}

int IsPrime(int num){
    if (num == 1) return 0;
    for (int i=2; i<=sqrt(num); ++i){
        if (num % i == 0) return 0;
    }
    return 1;
}