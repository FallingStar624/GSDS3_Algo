#include <iostream>
#define ll long long
using namespace std;

int n;
ll ans;
ll memo[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<n+1; i++) {
        cin >> memo[i];
    }
    ans=memo[1];
    for (int i=1; i<n+1; i++) {
        if ((memo[i]+memo[i-1])>memo[i]) {
            memo[i] += memo[i-1];
        }
        if (memo[i]>ans) {
            ans = memo[i];
        }
    }
    cout << ans;
    return 0;
}
