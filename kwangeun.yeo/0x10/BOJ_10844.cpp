#include <iostream>

using namespace std;

int N;
int D[101][12];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 2; i <= 10; ++i) {
        D[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= 10; ++j) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];
            D[i][j] %= 1000000000;
        }
    }
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += D[N][i];
        sum %= 1000000000;
    }
    cout << sum << '\n';

    return 0;
}