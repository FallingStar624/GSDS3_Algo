#include <iostream>
using namespace std;
int N;
int T[1500001];
int P[1500001];
int dp[1500001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> T[i];
        cin >> P[i];
    }
    for (int i=N; i>0; i--) {
        if (i+T[i]>N+1) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
        }
    }
    cout << dp[1];
    return 0;
}
