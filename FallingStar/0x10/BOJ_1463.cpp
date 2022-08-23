#include <iostream>
using namespace std;
int n;
int memo[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=2; i<=n; i++) {
        memo[i] = memo[i-1]+1;
        if (i%2==0) {
            memo[i] = min(memo[i], memo[i/2]+1);
        }
        if (i%3==0) {
            memo[i] = min(memo[i], memo[i/3]+1);
        }
    }
    cout << memo[n];
    return 0;
}
