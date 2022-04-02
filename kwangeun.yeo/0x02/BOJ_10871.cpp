#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n < X) cout << n << " ";
    }

    return 0;
}
