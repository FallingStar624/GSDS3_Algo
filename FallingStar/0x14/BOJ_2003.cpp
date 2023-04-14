#include <iostream>

using namespace std;

int A[10001];
int N, M, ans=0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for (int i=0; i<N; i++) {
        int tmp = A[i];
        if (tmp == M) ans++;
        for (int j=i+1; j<N; j++) {
            tmp += A[j];
            if (tmp == M) ans++;
        }
    }
    cout << ans;
    return 0;
}
