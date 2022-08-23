#include <iostream>
#include <algorithm>

using namespace std;
/*
algorithm
DP(i) = min(DP(i-1)+1, DP(i/2) +1, DP(i/3) +1)
*/

int DP(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(x == 3) return 1;
    // cout << " x: " << x << endl;
    int ans = DP(x-1)+1;
    if(x % 3 == 0){
        ans = min(DP(x-1)+1, DP(x/3)+1);
    }
    if(x % 2 == 0){
        ans = min(DP(x-1)+1, DP(x/2)+1);
    }
    return ans;
}


int main(){
    int N;
    int cnt = 0;
    cin >> N;
    cout << DP(N);
}