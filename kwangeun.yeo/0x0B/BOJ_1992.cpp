#include <iostream>

using namespace std;

int N;
char video[66][66];

bool search(int sr, int sc, int range, char num) {
    for (int i = 0; i < range; ++i) {
        for (int j = 0; j < range; ++j) {
            if (video[sr + i][sc + j] != num) return false;
        }
    }
    return true;
}

void func(int sr, int sc, int range) {
    char num = video[sr][sc];
    if (search(sr, sc, range, num)) {
        cout << num;
        return;
    }

    int half = range / 2;
    cout << '(';
    func(sr, sc, half);
    func(sr, sc + half, half);
    func(sr + half, sc, half);
    func(sr + half, sc + half, half);
    cout << ')';
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> video[r];
    }
    func(0, 0, N);

    return 0;
}