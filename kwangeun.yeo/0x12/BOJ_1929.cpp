#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int M, N;
    cin >> M >> N;
    vector<bool> is_prime(N + 1, true);
    is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = M; i <= N; ++i) {
        if (is_prime[i]) cout << i << '\n';
    }
    return 0;
}