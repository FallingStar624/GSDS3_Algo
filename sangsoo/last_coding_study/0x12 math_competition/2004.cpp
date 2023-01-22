// (n m)의 끝자리 0의 개수
// 1st row: 0<=m<=n<=2,000,000,000

#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;

int two(int n){
    int cnt =0;
    while(n!=0){
        n = n/2;
        cnt += n;
    }
    return cnt;
}

int five(int n){
    int cnt =0;
    while(n!=0){
        n = n/5;
        cnt += n;
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m; // order
    int cnt;
    // n! / m! (n-m)!
    cnt = min(two(n)-two(m)-two(n-m), five(n)-five(m)-five(n-m));

    cout<<cnt;
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 -> 10! 안에 있는 5의 개수 == 10//5
// 5, 25, 125 ...
// 나눗셈은 곧 개수에서는 -로 바꿔 생각