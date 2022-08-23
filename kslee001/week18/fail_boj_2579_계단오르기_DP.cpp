#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dp[301];
int arr[301];
bool ones[301]; // check 1 1 1

int main(){
    int n; cin >>n;
    for(int i=0; i<n; ++i) cin >>arr[i];

    // base
    dp[0] = arr[0];
    ones[0] = true; // 1-sized jump
    dp[1] = arr[0] + arr[1]; // jump to arr[1] and then to arr[2] 
                             // is always greater or equal than jump to arr[1] directly
    if(arr[0] + arr[1] > arr[1] ) ones[1] = true;   // had to 1-size jump twice       (last jump is 1-sized jump)
    else                          ones[1] = false;  // single 2-sized jump was enough (last jump is 2-sized jump)

    // cout << "arr[0] : "<<arr[0]<<" | dp[0] : "<< dp[0] <<"\n";
    // cout << "arr[1] : "<<arr[1]<<" | dp[1] : "<< dp[1] <<"\n";
    
    // dp
    for(int i=2; i<n; ++i){
        // dp[2] = max( dp[1]   + 1-sized jump if possible,  d[0]   + 2-sized jump )
        // dp[i] = max( dp[i-1] + 1-sized jump if possible,  d[i-2] + 2-sized jump )
        int jump1;
        int jump2;
        // check 1 1 1 jump
        if(ones[i-1]) jump1 = INT_MIN; // not available (1 1 1)
        else          jump1 = arr[i]; // available
        jump2 = arr[i];
        if(dp[i-1]+jump1 > dp[i-2]+jump2){
            dp[i] = dp[i-1]+jump1;
            ones[i] = true;
        }
        else{
            dp[i] = dp[i-2]+jump2;
        }
        // cout << "arr[" <<i<<"] : "<<arr[i]<<" | dp["<<i<<"] : "<< dp[i] << " | ones : "<< ones[i-1] << "\n";
    }
    // for(int i=0; i<n; ++i){
    //     cout << dp[i] << " ";
    // }
    cout << dp[n-1];



}