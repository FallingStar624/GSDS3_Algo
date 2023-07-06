#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){ // 최대공약수
    if (b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b){ // 최소공배수
    return (a * b) / GCD(a, b);
}

void solve(){
    int M, N, x, y, cnt = 1;
    cin >> M >> N >> x >> y;
    int maxnum = LCM(M, N);
    int year = maxnum + 1; // initialize year with a value greater than maxnum
    for(int i = x; i <= maxnum; i+=M){
        if ((i-1)%N+1 ==y || i > maxnum) {
            year = i;
            break;
        } // 값을 찾았거나 존재하지 않거나
    }
    if (year > maxnum) cout << -1 << '\n';
    else cout << year << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}