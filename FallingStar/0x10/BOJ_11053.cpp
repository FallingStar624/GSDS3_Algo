#include <iostream>
int N;
int ans;
int arr[1001];
int cnt[1001];
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    for (int i=1; i<=N; i++) {
        cnt[i]=1;
        for (int j=1; j<=i; j++) {
            if (arr[i] > arr[j]) {
                cnt[i] = max(cnt[i], cnt[j]+1);
            }
        }
        ans = max(cnt[i], ans);
    }
    cout << ans;
    return 0;
}
