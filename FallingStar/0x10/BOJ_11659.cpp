#include <iostream>
using namespace std;
int n, m;
int memo[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<n+1; ++i) {
        int tmp;
        cin >> tmp;
        memo[i] = tmp + memo[i-1];
    }
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << memo[b] - memo[a-1] << '\n';
    }
    return 0;
}
