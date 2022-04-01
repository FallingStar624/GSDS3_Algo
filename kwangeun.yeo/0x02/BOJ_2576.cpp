#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, min, sum;
    sum = 0;
    min = 101;
    for (int i = 0; i < 7; ++i) {
        cin >> n;
        if (n % 2 == 0) continue;
        sum += n;
        if (min > n) min = n;
    }
    if (sum == 0) cout << -1;
    else cout << sum << '\n' << min;

    return 0;
}
