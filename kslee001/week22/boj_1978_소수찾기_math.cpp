// 소수
// https://www.acmicpc.net/problem/1978
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){   // O(n)
    if(n==1) return false;
    for(int i=2; i<n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

// 합성수 N에서 1을 제외한 가장 작은 약수는 sqrt(N) 이하
// -> sqrt(N) 이하의 가장 작은 약수들만 구하고, 이것에 대해서만 계산하면 된다.

bool isprime_sqrt(int n){ // O(sqrt N)
    if(n==1) return false;
    for(int i=2; i*i<=n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int t; cin >>t;
    int res=0;
    for(int i=0; i<t; ++i){
        int n; cin>>n;
        res += isprime_sqrt(n);
    }
    cout << res;
}
