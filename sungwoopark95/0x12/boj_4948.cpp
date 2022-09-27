#include <iostream>
#include <math.h>
using namespace std;

int N;
bool IsPrime(int N) {
    if (N == 1) { return false; }
    float N_sqrt = sqrt(N);
    for (int i=2;i<=N_sqrt;i++) {
        if (N % i == 0) { return false; }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while (1) {
        cin >> N;
        if (N == 0) { return 0; }
        int cnt = 0;
        for (int i=N+1;i<=2*N;i++) {
            if (IsPrime(i)) { cnt++; }
        }
        cout << cnt << "\n";
    }
    return 0;
}