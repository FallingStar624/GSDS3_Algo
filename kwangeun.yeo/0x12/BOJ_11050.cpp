#include <iostream>
using namespace std;

int D[1002][1002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    for (int n = 1; n <= N; ++n) {
        D[n][0] = D[n][n] = 1;
        D[n][1] = n;
        for (int k = 2; k <= K && k < n; ++k) {
            D[n][k] = (D[n - 1][k] + D[n - 1][k - 1]) % 10007;
        }
    }
    cout << D[N][K];
    return 0;
}