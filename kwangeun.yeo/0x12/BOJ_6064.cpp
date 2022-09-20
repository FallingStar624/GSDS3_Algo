#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int func(int M, int N, int x, int y) {
    if (x == M) x = 0;
    if (y == N) y = 0;
    int end = lcm(M, N);
    int k;
    for (k = x; k <= end; k += M) {
        if (k == 0) continue;
        if (k % N == y) return k;
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    int M, N, x, y;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> M >> N >> x >> y;
        cout << func(M, N, x, y) << '\n';
    }
    return 0;
}