#include <bits/stdc++.h>
using namespace std;

int find(int N, int r, int c) {
    if (N == 0) { return 0; }
    int half = pow(2, N) / 2;
    if (r < half && c < half) { return find(N-1, r, c); }
    if (r < half && c >= half) { return (half*half) + find(N-1, r, c-half); }
    if (r >= half && c < half) { return (2*half*half) + find(N-1, r-half, c); }
    else { return (3*half*half) + find(N-1, r-half, c-half); }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N, r, c;
    cin >> N >> r >> c;
    
    cout << find(N, r, c) << "\n";
    
    return 0;
}