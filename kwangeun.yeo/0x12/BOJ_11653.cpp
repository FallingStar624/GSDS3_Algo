#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        if (i * i > N) {
            if (i != 1) cout << N << '\n';
            break;
        }
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
    return 0;
}