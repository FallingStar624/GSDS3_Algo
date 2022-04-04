#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h[9];
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        cin >> h[i];
        sum += h[i];
    }
    sort(h, h + 9);
    int target = sum - 100;
    sum = 0;
    int i, j;
    for (i = 0; i < 8; ++i) {
        for (j = i + 1; j < 9; ++j) {
            if (h[i] + h[j] == target) break;
        }
        if (j != 9) break;
    }
    for (int k = 0; k < 9; ++k) {
        if (k == i || k == j) continue;
        cout << h[k] << '\n';
    }

    return 0;
}
