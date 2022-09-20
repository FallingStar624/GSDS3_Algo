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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while (T--) {
        cin >> M >> N >> x >> y;
        int x_coord = 1; 
        int y_coord = 1;
        int year = 1;
        while (year <= LCM(M, N)) {
            if (x_coord == M) { x_coord = M; }
            else { x_coord %= M; }
            
            if (y_coord == N) { y_coord = N; }
            else { y_coord %= N; }
            
            mp[{x_coord++, y_coord++}] = year++;
        }
        
        if (mp.count({x, y}) > 0) { cout << mp[{x, y}] << "\n"; }
        else { cout << -1 << "\n"; }
    }
    
    return 0;
}