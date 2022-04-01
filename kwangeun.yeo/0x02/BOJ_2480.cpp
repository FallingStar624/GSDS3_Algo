#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, ret;
    cin >> a >> b >> c;
    if (a == b && b == c && c == a) ret = 10000 + (a * 1000);
    else if (a == b || c == a) ret = 1000 + (a * 100);
    else if (b == c) ret = 1000 + (b * 100);
    else ret = max({a, b, c}) * 100;
    cout << ret;

    return 0;
}
