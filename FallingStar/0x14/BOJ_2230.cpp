#include <iostream>
#include <algorithm>
#define INF 2000000000

using namespace std;

int A[100001];
int N, M, ans=INF;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A, A+N);
    int s=0, e=0;
    while (s<N && e<N) {
        int tmp = A[e]-A[s];
        if (tmp< M) {
            e++;
        } else {
            ans = min(ans, tmp);
            s++;
        }
    }
    cout << ans;
    return 0;
}
