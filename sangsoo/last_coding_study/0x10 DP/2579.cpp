#include <iostream>
#include <algorithm>
using namespace std;

/*
algorithm
    max(dp[n-3] + point[n-1] + point[n], dp[n-2] + point[n])
*/

int main(){
    int point[302]; // point of each step
    int dp[302]; // accumulated values

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> point[i];
    }
    dp[0] = 0;
    dp[1] = point[1];
    dp[2] = point[1] + point[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-3] + point[i-1] + point[i], dp[i-2] + point[i]);
    }
    cout << dp[n];

}