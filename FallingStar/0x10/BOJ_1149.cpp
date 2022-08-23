#include <iostream>
using namespace std;
int n, ans;
int cost_r[1001];
int cost_g[1001];
int cost_b[1001];
int now_r[1001];
int now_g[1001];
int now_b[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> cost_r[i] >> cost_g[i] >> cost_b[i];
    }
    for (int i=1; i<=n; i++) {
        now_r[i] = min(now_g[i-1], now_b[i-1]) + cost_r[i];
        now_g[i] = min(now_r[i-1], now_b[i-1]) + cost_g[i];
        now_b[i] = min(now_r[i-1], now_g[i-1]) + cost_b[i];
    }
    ans = min(now_r[n], now_g[n]);
    ans = min(ans, now_b[n]);
    cout << ans;
    return 0;
}
