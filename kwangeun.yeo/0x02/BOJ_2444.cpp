#include <bits/stdc++.h>

using namespace std;

int N;

void draw(int L) {
    if (L >= N) {
        for (int i = 0; i < 2 * N - 1; ++i) {
            cout << "*";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N - L; ++i) {
        cout << " ";
    }
    for (int i = 0; i < 2 * L - 1; ++i) {
        cout << "*";
    }
    cout << "\n";
    draw(L + 1);
    for (int i = 0; i < N - L; ++i) {
        cout << " ";
    }
    for (int i = 0; i < 2 * L - 1; ++i) {
        cout << "*";
    }
    cout << "\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    draw(1);

    return 0;
}