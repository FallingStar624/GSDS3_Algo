#include <iostream>
#include <algorithm>

using namespace std;

int d[10005];
int mod = 10007;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2]) % mod;
    }
    cout << d[n];

    return 0;
}