#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}