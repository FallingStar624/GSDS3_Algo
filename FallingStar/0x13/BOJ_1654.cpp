#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int K, N;
int a[10005];

bool solve(ll x) {
    ll cur = 0;
    for (int i=0; i< K; i++) {
        cur += a[i]/x;
    }
    return cur >= N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> K >> N;
    ll st = 0;
    ll en = 0x7fffffff;
    for (int i=0; i<K; i++) {
        cin >> a[i];
    }
    while (st < en) {
        ll mid = (st+en+1)/2;
        if (solve(mid)) st = mid;
        else en=mid-1;
    }

    cout << st;
    return 0;
}
