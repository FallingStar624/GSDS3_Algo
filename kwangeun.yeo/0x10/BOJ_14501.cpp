#include <iostream>

using namespace std;

int N;
int T[20];
int P[20];
int D[20];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; --i) {
        if (i + T[i] > N + 1) D[i] = D[i + 1];
        else {
            D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
        }
    }
    cout << D[1];

    return 0;
}