#include <bits/stdc++.h>
using namespace std;

// using ll = long long;

long long POW(long long a, long long b, long long m){
    printf("-------------start---------------\n");
    printf("a = %lld, b = %lld, m = %lld\n", a, b, m);
    if(b==1){
        printf("b == 1, a = %lld, b = %lld, m = %lld\n", a, b, m);
        printf("return a %% b = %lld\n", a%m);
        return a % m;
    }
    long long val = POW(a, b/2, m);
    printf("--------------------------------\n");
    printf("val = %lld, a = %lld, b = %lld, m = %lld\n", val, a, b, m);
    val = val * val % m;
    printf("val = %lld\n", val);
    if (b%2 == 0) {
        printf("val = %lld, b % 2 ==0, a = %lld, b = %lld, m = %lld\n", val, a, b, m);
        return val;
    }
    printf("--------------------------------\n");
    printf("val = %lld, a = %lld, b = %lld, m = %lld\n", val, 
    a, b, m);
    return val * a % m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    printf("main function : a = %lld, b = %lld, c = %lld\n", a, b, c);
    cout << POW(a, b, c);
}



