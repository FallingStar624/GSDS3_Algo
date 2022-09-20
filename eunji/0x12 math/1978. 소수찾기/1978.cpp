/*
주어진 수 N개 중 소수 몇 개?

input : 
수의 개수 N (N<=100)
수는 1000이하의 자연수
*/


#include <iostream>
using namespace std;

int N;
int num[1002];
int answer;
int IsPrime(int a);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> num[i];
        if (IsPrime(num[i])) answer ++;
    }

    cout << answer;

    return 0;
}

int IsPrime(int a){
    int is_prime = 1;
    if (a == 1) return 0;
    for (int i=2; i<a; ++i){
        if (a % i == 0) is_prime = 0;
    }
    return is_prime;
}