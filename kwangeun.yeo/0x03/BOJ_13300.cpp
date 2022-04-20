#include <bits/stdc++.h>
using namespace std;

int N, K;
int student[2][7];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    int s, y;
    for (int i = 0; i < N; ++i) {
        cin >> s >> y;
        student[s][y]++;
    }
    int rooms = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= 6; ++j) {
            rooms += ((student[i][j] / K) + ((student[i][j] % K) ? 1 : 0));
        }
    }
    cout << rooms;

    return 0;
}
