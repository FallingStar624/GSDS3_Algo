#include <iostream>
using namespace std;

int A[100005];
int ans=100005;
int n, s, sum;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for (int i=0; i<n; i++) cin >> A[i];
    int en=0;
    sum=A[0];
    for (int st=0;st<n; st++) {
        while (en<n && sum < s) {
            en++;
            if(en!=n) sum+=A[en];
        }
        if (en==n) break;
        ans = min(ans, en-st+1);
        sum -= A[st];
    }
    if (ans == 100005) ans = 0;
    cout << ans;
    return 0;

