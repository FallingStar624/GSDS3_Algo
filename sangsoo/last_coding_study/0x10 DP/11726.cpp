#include <iostream>
using namespace std;
/*
algorithm
dp[n] = dp[n-1] + dp[n-2];
dp[n-1] : 2*1
dp[n-2] : (1*2)*2
*/

int main(){
    int dp[1002];
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout << dp[n];

}