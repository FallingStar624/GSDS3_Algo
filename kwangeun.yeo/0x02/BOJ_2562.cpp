#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int maxnum = 0;
    int maxidx = 0;
    int num;
    for (int i = 0; i < 9; ++i) {
        cin >> num;
        if (num > maxnum) {
            maxnum = num;
            maxidx = i;
        }
    }
    cout << maxnum << '\n' << maxidx + 1;

    return 0;
}
