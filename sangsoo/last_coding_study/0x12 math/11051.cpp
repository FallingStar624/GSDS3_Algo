#include <iostream>
using namespace std;

int dp[1002][1002];

int main(){
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= 1000; i++){
        dp[i][0] = 1;
        for(int j = 1; j <=i ; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    int n, m;
    cin >> n >> m;
    cout << dp[n][m];
}
