#include <iostream>

using namespace std;

int N;
bool chk_col[15];
bool chk_diag_left[30]; // x + y
bool chk_diag_right[30]; // x - y + n - 1
int cnt;

void func(int row) {
    if (row >= N) {
        cnt++;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (chk_col[col]) continue;
        if (chk_diag_left[row + col]) continue;
        if (chk_diag_right[row - col + N - 1]) continue;
        chk_col[col] = true;
        chk_diag_left[row + col] = true;
        chk_diag_right[row - col + N - 1] = true;
        func(row + 1);
        chk_col[col] = false;
        chk_diag_left[row + col] = false;
        chk_diag_right[row - col + N - 1] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    cnt = 0;
    func(0);
    cout << cnt;

    return 0;
}