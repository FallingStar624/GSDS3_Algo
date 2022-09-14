#include <iostream>
#include <algorithm>
using namespace std;


// 15 * 5 = 75

/*
T  T  T
      10 
   T  T  T  T  T
               20
      T
      10
          T
          20
             T  T
                15
                T  T  T  T
                         40
                   T  T
                      200 
*/

int dp[100];
int reward[100];
int timecost[100];
int n;

int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> timecost[i]>>reward[i];
    }

    for(int i=n; i>=1; --i){
        if( i+timecost[i] > n+1){
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(dp[i+timecost[i]] + reward[i], dp[i+1]);
    }
    cout << *max_element(dp, dp+n+1);
}