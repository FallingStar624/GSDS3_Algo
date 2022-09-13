#include <iostream>
int T;
long dp[101];
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    for (int i=6; i<101; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    for (int i=0; i<T; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }
    return 0;
}
