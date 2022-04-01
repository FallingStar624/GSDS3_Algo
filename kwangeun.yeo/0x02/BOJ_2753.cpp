#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y;
    cin >> y;
    cout << (y % 400 == 0 || y % 100 != 0 && y % 4 == 0) ? 1 : 0;

    return 0;
}
