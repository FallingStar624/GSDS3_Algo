#include <iostream>
#include <algorithm>
using namespace std;
int N, K;

int permute(int n) {
    int result = 1;
    for (int i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    int ans = 1;
    ans *= permute(N);
    ans /= permute(K);
    ans /= permute(N-K);
    cout << ans;
    return 0;
}
