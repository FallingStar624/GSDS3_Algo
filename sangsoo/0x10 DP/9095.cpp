#include <iostream>

using namespace std;

/*
algorithm : dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
1) dp[n-1] add number 1
2) dp[n-2] add number 2 
3) dp[n-3] add number 3
*/

int dp[11];

int main(){
    dp[1] = 1; // (1)
    dp[2] = 2; // (1,1), (2)
    dp[3] = 4; // (1,1,1), (1,2), (2,1), (3)
    dp[4] = 7; // (1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1)

    for(int i = 5; i < 11 ; i++){
        dp[i] = dp[i-1] + dp[i-2]+ dp[i-3];
    }
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int j;
        cin >> j;
        cout << dp[j] << '\n';
    }

}