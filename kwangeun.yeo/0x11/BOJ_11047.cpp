#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N, K;
    cin >> N >> K;
    int coin[11];
    for (int i = 0; i < N; ++i) {
        cin >> coin[i];
    }
    int cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        cnt += (K / coin[i]);
        K %= coin[i];
        if (K == 0) break;
    }
    cout << cnt;

    return 0;
}