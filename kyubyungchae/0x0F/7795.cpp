#include <iostream>
#include <algorithm>

using namespace std;

int t;
int n, m;
int A[20001];
int B[20001];

int func() {

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int a = A[i];
        if(a < B[0]) continue;
        if(a > B[m-1]) {
            cnt += m;
        } else {
            for(int j = 0; j < m; j++) {
                if(a > B[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for(int j = 0; j < m; j++) {
            cin >> B[j];
        }

        sort(A, A + n);
        sort(B, B + m);

        cout << func() << '\n';

    }
    return 0;
}