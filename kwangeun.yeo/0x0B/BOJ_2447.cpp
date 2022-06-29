#include <iostream>

using namespace std;

int N;
char star[2400][2400];

void func(int sr, int sc, int range) {
    if (range == 1) {
        star[sr][sc] = '*';
        return;
    }
    int next_range = range / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            func(sr + next_range * i, sc + next_range * j, next_range);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            star[i][j] = ' ';
        }
    }
    func(0, 0, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}