#include <iostream>
#include <algorithm>
using namespace std;
int dp[1002][1002];
int N, K;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    dp[0][0] = 1;
    for (int i=1; i<=N+1; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0) {
                dp[i][j] = 1;
            } else if (j==i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j-1]%10007 + dp[i-1][j]%10007;
                dp[i][j] %= 10007;
            }
        }
    }
    cout << dp[N][K]<< endl;
    return 0;
}
