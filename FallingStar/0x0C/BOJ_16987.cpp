#include <iostream>
using namespace std;
int n, cnt, maximum;
int s[8];
int w[8];

void back_track(int idx) {
    if (idx==n) {
        maximum = max(maximum, cnt);
        return;
    }
    if (s[idx]<=0 || cnt==n-1) {
        back_track(idx+1);
        return;
    }
    for (int i=0; i<n; i++) {
        if (i==idx || s[i]<=0) continue;
        s[idx] -= w[i];
        s[i] -= w[idx];
        if (s[idx]<=0) cnt++;
        if (s[i]<=0) cnt++;
        back_track(idx+1);
        if (s[idx]<=0) cnt--;
        if (s[i]<=0) cnt--;
        s[idx] += w[i];
        s[i] += w[idx];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> w[i];
    }
    back_track(0);
    cout << maximum;
    return 0;
}
