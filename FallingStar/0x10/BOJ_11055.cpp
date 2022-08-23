#include <iostream>
using namespace std;

int n, ans, before;
int num[1000];
int memo[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
            cin >> num[i];
    }
    for (int i=0; i<n; i++) {
        memo[i] = num[i];
        for (int j=0; j<i; j++) {
            if (num[j]<num[i]) {
                memo[i] = max(memo[i], memo[j]+num[i]);
            }
        }
        ans = max(ans, memo[i]);
    }
    cout << ans;
    return 0;
}
