#include <iostream>
#include <algorithm>
using namespace std;
int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int A[N];
    int B[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    for (int i=0; i<N; i++) {
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    int ans=0;
    for (int i=0; i<=N; i++) {
        ans += A[i]*B[N-1-i];
    }
    cout << ans;
    return 0;
}
