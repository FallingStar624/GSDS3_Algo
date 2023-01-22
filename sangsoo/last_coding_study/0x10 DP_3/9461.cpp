#include <iostream>
using namespace std;

/*
algorithm
dp[n] = dp[n-2] + dp[n-3]
*/
int n;
long long dp[102];
int arr[102];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < 101; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    for(int i = 0; i < n; i++){
        cout << dp[arr[i]] << '\n';
    }
}