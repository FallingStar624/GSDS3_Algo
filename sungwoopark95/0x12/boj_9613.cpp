#include <iostream>
using namespace std;

int T, N;

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


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while (T--) {
        cin >> N;
        unsigned long long arr[N];
        for (int i=0;i<N;i++) {
            cin >> arr[i];
        }
        
        unsigned long long sum = 0;
        for (int i=0;i<N;i++) {
            for (int j=i+1;j<N;j++) {
                sum += GCD(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}