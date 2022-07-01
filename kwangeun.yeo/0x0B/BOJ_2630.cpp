#include <iostream>

using namespace std;

int N;
int result[2];
int paper[130][130];

bool search(int sr, int sc, int range, int color) {
    for (int i = 0; i < range; ++i) {
        for (int j = 0; j < range; ++j) {
            if (paper[sr + i][sc + j] != color) return false;
        }
    }
    return true;
}

void func(int sr, int sc, int range) {
    int color = paper[sr][sc];
    if (search(sr, sc, range, color)) {
        result[color]++;
        return;
    }

    int half = range / 2;
    func(sr, sc, half);
    func(sr, sc + half, half);
    func(sr + half, sc, half);
    func(sr + half, sc + half, half);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> paper[r][c];
        }
    }
    func(0, 0, N);
    cout << result[0] << '\n' << result[1];

    return 0;
}