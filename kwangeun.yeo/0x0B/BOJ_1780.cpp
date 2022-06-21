#include <iostream>

using namespace std;

int N;
int paper[2700][2700];

bool search(int sr, int sc, int n, int trg) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (paper[sr + r][sc + c] != trg) return false;
        }
    }
    return true;
}

int func(int sr, int sc, int n, int trg, int cnt) {
    if (n == 0) return cnt;
    if (search(sr, sc, n, trg)) {
        return cnt + 1;
    }
    else {
        int sep = n / 3;
        int sum = 0;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                sum += func(sr + (r * sep), sc + (c * sep), sep, trg, cnt);
            }
        }
        return sum;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    cout << func(0, 0, N, -1, 0) << '\n';
    cout << func(0, 0, N, 0, 0) << '\n';
    cout << func(0, 0, N, 1, 0) << '\n';

    return 0;
}