#include <iostream>
int N;
long dp[10][101];
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=1; i<10; i++) {
        dp[i][1]=1;
    }
    for (int i=2; i<101; i++) {
        for (int j=0; j<10; j++) {
            if (j==0) {
                dp[j][i] = dp[1][i-1]%1000000000;
            } else if (j==9) {
                dp[j][i] = dp[8][i-1]%1000000000;
            } else {
                dp[j][i] = dp[j-1][i-1]%1000000000 + dp[j+1][i-1]%1000000000;
            }
        }
    }
    long ans=0;
    for (int i=0; i<10; i++) {
        ans += dp[i][N]%1000000000;
    }
    cout << ans%1000000000;
    return 0;
}
