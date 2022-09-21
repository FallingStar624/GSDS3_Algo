#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (;;) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<bool> is_prime(2 * n + 1, true);
        is_prime[1] = false;
        for (int i = 2; i * i <= 2 * n; ++i) {
            for (int j = i * i; j <= 2 * n; j += i) {
                is_prime[j] = false;
            }
        }
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (is_prime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}