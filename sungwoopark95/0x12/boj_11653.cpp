#include <iostream>
#include <math.h>
using namespace std;

int N, idx;
int primes[3200];

bool IsPrime(int x) {
    if (x == 1) { return false; }
    double x_sqrt = sqrt(x);
    for (int i=2;i<=x_sqrt;i++) {
        if (x % i == 0) { return false; }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    
    // sqrt(N)까지의 소수만 담아놓으면 됨
    for (int i=1;i<=sqrt(N);i++) {
        if (IsPrime(i)) { primes[idx++] = i; }
    }
    
    for (int i=0;i<idx;i++) {
        int prime = primes[i];
        while (N % prime == 0) { 
            cout << prime << "\n"; 
            N /= prime;
        }
    }
    
    if (N == 1) { return 0; }
    else { cout << N << "\n"; }
    
    return 0;
}