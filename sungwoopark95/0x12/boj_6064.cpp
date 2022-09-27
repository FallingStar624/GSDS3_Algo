#include <iostream>
#include <map>
using namespace std;

int T, M, N, x, y;
map<pair<int, int>, int> mp;

int GCD(int N, int M) {
    int minval, maxval;
    if (N < M) { 
        minval = N; 
        maxval = M;
    } else { 
        minval = M; 
        maxval = N;
    }
    
    int mod;
    while (minval != 0) {
        mod = maxval % minval;
        maxval = minval;
        minval = mod;
    }
    return maxval;
}

int LCM(int N, int M) {
    return (N*M) / GCD(N, M);
}

int Cnt(int M, int N, int x, int y) {
    if (x == M) { x = 0; }
    if (y == N) { y = 0; }
    for (int year=x;year<=LCM(M, N);year+=M) {
        if (year == 0) { continue; }
        if (year % N == y) {
            return year;
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while (T--) {
        cin >> M >> N >> x >> y;
        cout << Cnt(M, N, x, y) << "\n";
    }
    
    return 0;
}