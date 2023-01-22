#include <iostream>
#include <algorithm>

using namespace std;
/*
algorithm
DP(i) = min(DP(i-1)+1, DP(i/2) +1, DP(i/3) +1)
*/

int arr_dp[1000002];

int main(){
    cout << min(1, 3, 4);
    cout << min(10, 8, 2);
}