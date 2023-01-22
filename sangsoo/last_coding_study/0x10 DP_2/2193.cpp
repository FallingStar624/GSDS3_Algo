#include <iostream>
/*
algorithm
f[n] = f[n-1]+ f[n-2];

* int : -2,147,483,648~ 2,147,483,647
* unsigned int : 0~4,294,967,295
* long long : -9,223,372,036,854,775,808~9,223,372,036,854,775,807
* unsigned long long : 0~18,446,744,073,709,551,615	
*/

using namespace std;

long long dp[92];

int main(){
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<92; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n;
    cin >> n;
    cout << dp[n];

}