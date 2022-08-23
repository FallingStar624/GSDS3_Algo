/*
10
1 100 2 50 60 3 5 6 7 8
--
113
*/

#include <iostream>
using namespace std;

int arr[1001];
int dp [1001];
int res;

int main(){
    int n; cin >>n;
    for(int i=1; i<=n; ++i) cin >>arr[i];

    // base case
    dp[1] = arr[1];
    dp[2] = max(arr[2], dp[1] + arr[2]);

    // dp
    for(int i=3; i<=n; ++i){ // 기준점
        int left = i-1;
        int leftmax = i;
        
        int sum = arr[leftmax];
        while(left >= 1){
            if( arr[left] < arr[leftmax] && dp[left] > sum ){
                sum += arr[left];
                leftmax = left;
            }
            --left;
        }
        dp[i] = sum;
    }

    for(int i=1; i<=n; ++i) cout << dp[i] <<" ";
    // for(int i=0; i<n; ++i) if(dp[i] > res) res = dp[i];
    // cout << res;
}