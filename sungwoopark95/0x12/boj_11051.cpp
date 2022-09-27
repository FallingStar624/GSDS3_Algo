#include <iostream>
using namespace std;

int N, K;
long long combdp[1003][1003];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;

    for (int i=1;i<=N;i++) {
        combdp[i][0] = 1;
        combdp[i][i] = 1;
        for (int j=1;j<i;j++) {
            combdp[i][j] = (combdp[i-1][j] + combdp[i-1][j-1]) % 10007;
        }
    }
    
    cout << combdp[N][K] << "\n";
    return 0;
}