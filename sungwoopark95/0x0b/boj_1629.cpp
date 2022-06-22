#include <bits/stdc++.h>
using namespace std;

long long mulHelp(long long x, long long n, long long y) {
    if (n == 1) { 
        return x % y; 
    }
    else { 
        long long val = mulHelp(x, n/2, y);
        val = (val * val) % y;
        if (n % 2 == 0) {
            return val;
        } else {
            return (x * val) % y;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << mulHelp(A, B, C) << "\n";
    
    return 0;
}