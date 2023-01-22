#include <iostream>

/*
algorithm
if n : even number
    f(n) = 2*f(n-1)+1
else n : odd number
    f(n) = 2*f(n-1)-1
*/

using namespace std;

int dp[1002];

int main(){
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i < 1001 ; i++){
        if(i%2 == 0) // i : an even number
            dp[i] = (2*dp[i-1]+1)%10007;
        else // i : an odd number
            dp[i] = (2*dp[i-1]-1)%10007;
    }
    int n;
    cin >> n;
    cout << dp[n]%10007;
}