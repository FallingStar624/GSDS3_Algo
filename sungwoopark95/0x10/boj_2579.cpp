#include <iostream>
#include <algorithm>
using namespace std;

int N;
int D[303][3];
int stair[303];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) { cin >> stair[i]; }
    
    D[1][0] = stair[1]; D[1][1] = stair[1]; D[1][2] = 0;

    for (int k=2;k<=N;k++) {
        D[k][1] = max(D[k-2][1], D[k-2][2]) + stair[k];
        D[k][2] = D[k-1][1] + stair[k];
        D[k][0] = max(D[k][1], D[k][2]);
    }
    
    cout << D[N][0] << "\n";
    
    return 0;
}