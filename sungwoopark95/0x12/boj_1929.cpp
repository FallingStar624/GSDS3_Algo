#include <iostream>
#include <math.h>
using namespace std;

int M, N;

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
    
    cin >> M >> N;
    // make a prime number table until the max_element
    for (int i=M;i<=N;i++) {
        if (IsPrime(i)) { cout << i << "\n"; }
    }

    return 0;
}