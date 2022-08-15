#include <iostream>
using namespace std;

int N;
int D[1000005];
int path[1000005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    D[1] = 0;
    path[1] = 1;
    
    for (int i=2;i<=N;i++) {
        int m = D[i-1] + 1;
        int k = i - 1;
        if (i%2 == 0) {
            if (m > D[i/2]+1) {
                m = D[i/2] + 1;
                k = i / 2;
            }
        }
        if (i%3 == 0) {
            if (m > D[i/3]+1) {
                m = D[i/3] + 1;
                k = i / 3;
            }
        }
        
        D[i] = m;
        path[i] = k;
    }
    
    cout << D[N] << "\n";
    int cur = N;
    while (cur >= 1) {
        cout << cur << " ";
        if (cur == 1) { break; }
        cur = path[cur];
    }
    cout << "\n";
    
    return 0;
}