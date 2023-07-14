#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, m, tot;
ll a[10005];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    int st = 0, en = 0;
    int cnt = 0;
    
    while (en <= n) {
        ll csum = a[en] - a[st];
        if(csum <= m) {
            if(csum == m)
                cnt++;
            en++;
        }
        else 
            st++;
    }

    cout << cnt;
    return 0;
}