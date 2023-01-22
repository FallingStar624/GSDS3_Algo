#include <iostream>
#include <algorithm>

using namespace std;
/*
algorithm
DP(i) = min(DP(i-1)+1, DP(i/2) +1, DP(i/3) +1)
*/

int arr_dp[1000002];

int main(){
    int N;
    cin >> N;
    arr_dp[1] = 0;
    arr_dp[2] = 1;
    arr_dp[3] = 1;
    for (int i = 4; i <= N; i++){
        arr_dp[i] = arr_dp[i-1]+1;
        if(i % 3 == 0){
            arr_dp[i] = min(arr_dp[i], arr_dp[i/3]+1);
        }
        if(i % 2 == 0){
            arr_dp[i] = min(arr_dp[i], arr_dp[i/2]+1);
        }
    }

    cout << arr_dp[N];
}