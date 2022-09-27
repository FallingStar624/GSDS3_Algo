#include <iostream>
using namespace std;

int T;
unsigned long long N, M;

unsigned long long GCD(unsigned long long N, unsigned long long M) {
    unsigned long long minval, maxval;
    if (N < M) { 
        minval = N; 
        maxval = M;
    } else { 
        minval = M; 
        maxval = N;
    }
    
    unsigned long long mod;
    while (minval != 0) {
        mod = maxval % minval;
        maxval = minval;
        minval = mod;
    }
    return maxval;
}

unsigned long long LCM(unsigned long long N, unsigned long long M) {
    return (N*M) / GCD(N, M);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << LCM(N, M) << "\n";   
    }

    return 0;
}