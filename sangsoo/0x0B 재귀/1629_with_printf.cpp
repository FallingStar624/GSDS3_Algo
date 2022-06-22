#include <bits/stdc++.h>
using namespace std;

// using ll = long long;

long long POW(long long a, long long b, long long m){
    if(b==1){
        return a % m;
    }
    long long val = POW(a, b/2, m);
    val = val * val % m;
    if (b%2 == 0) {
        return val;
    }
    return val * a % m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}



