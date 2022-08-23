/*
문제 : 
N자리 이친수의 개수를 구하는 프로그램
이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 

Input : N(1 ≤ N ≤ 90)
Output : N자리 이친수의 개수
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
long long D[92];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    D[1] = 1;
    D[2] = 1;

    for (int i=3; i<=N; i++){
        D[i] = D[i-1] + D[i-2];
    }

    cout << D[N] ;
}