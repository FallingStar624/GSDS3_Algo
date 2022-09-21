#include <iostream>
using namespace std;
// n개중 k개를 고르는 문제
// n! / k!(n-k)!
/*
5개중 2개 ->

5 4 3 2 1  -> 5 4  (n에서 k개만)
2 1 3 2 1  -> 2 1  (k!)
*/

int solve(int n, int k){
    int up=1, down=1;
    for(int i=0; i<k; ++i)
        up*=(n-i);
    for(int i=k; i>=1; --i)
        down*=i;
    return up/down;
}

int main(){
    int n,k; cin >>n>>k;
    cout << solve(n,k);
}