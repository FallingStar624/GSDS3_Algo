#include <iostream>

using namespace std;

long long d[101];

/*
- d[i] : i번째 변의 길이
- d[k] = d[k-1] + d[k-5]
- d[1] = 1
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;

    for(int i = 6; i <= 100; i++) {
        d[i] = d[i-1] + d[i-5];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}