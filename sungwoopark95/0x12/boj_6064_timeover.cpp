#include <iostream>
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
    int x_coord = 1; 
    int y_coord = 1;
    int year = 1;
    while (year <= LCM(M, N)) {
        if (x_coord == M) { x_coord = M; }
        else { x_coord %= M; }
        
        if (y_coord == N) { y_coord = N; }
        else { y_coord %= N; }
        
        if (x_coord == x && y_coord == y) { return year; }
        x_coord++;
        y_coord++;
        year++;
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