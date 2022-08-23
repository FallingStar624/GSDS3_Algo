#include <iostream>
using namespace std;
int n;
int memo[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n+1; i++) {
        if (i==0) {memo[i]=1; continue;}
        if (i==1) {memo[i]=1; continue;}
        if (i==2) {memo[i]=2; continue;}
        memo[i] = memo[i-1]%10007 + memo[i-2]%10007;
    }
    cout << memo[n]%10007;
    return 0;
}
