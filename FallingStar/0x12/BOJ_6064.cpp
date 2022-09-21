#include <iostream>
#include <numeric>
using namespace std;
int M, N, x, y, T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> M >> N >> x >> y;
        int mx = gcd(M, N);
        mx = (M*N)/mx;
        int ans = -1;
        if (x==M) x=0;
        if (y==N) y=0;
        for (int i=x; i<=mx; i+=M) {
            if (i==0) continue;
            if (i%N == y) {
                ans = i;
                break;
            }
        }
        if (t==T-1) {
            cout << ans;
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
