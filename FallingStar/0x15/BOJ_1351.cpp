#include <unordered_map>
#include <iostream>
#define ll long long
using namespace std;

ll N, P, Q;
unordered_map<ll, ll> m;

ll dfs(ll x) {
    if (x == 0) return 1;
    if (m[x] != 0) return m[x];
    return m[x] = dfs(x/P) + dfs(x/Q);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> P >> Q;
    ll ans = dfs(N);
    cout << ans << endl;
    return 0;
}
