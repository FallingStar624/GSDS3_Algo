// similar to 1463
#include <iostream>
#include <algorithm>

using namespace std;

/*
algorithm
dp[n] = min(dp[n-1]+1,dp[n/2]+1, dp[n/3]+1);
*/

int main(){
    int dp[1000002]; int chg[1000002];
    int n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    chg[3] = 1;
    chg[2] = 1;
    chg[1] = 0;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] +1;
        chg[i] = i-1;
        if(i % 2 == 0 && dp[i] > dp[i/2]+1){
            dp[i] = dp[i/2]+1;
            chg[i] = i/2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3]+1){
            dp[i] = dp[i/3]+1;
            chg[i] = i/3;
        }
    }
    
    cout << dp[n] << '\n';
    // for(int i = n; i>=1; i--){
    //     cout << "chg[" << i << "] = "<< chg[i] << endl;
    //     cout << "dp[" << i << "] = "<< dp[i] << endl;
    // }
    while(n>0){
        cout << n << " ";
        n = chg[n];
    }
}