#include <iostream>
#include <string>
using namespace std;
string a;
string b;
int dp[1001][1001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> a >> b;
    int N = a.size();
    int M = b.size();
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<M+1; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i-1]==b[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }
    cout << dp[N][M];
    return 0;
}
