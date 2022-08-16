#include <iostream>
#include <algorithm>
using namespace std;

int N;
int table[1002][3];

int D[1002][3]; //

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<3;j++) {
            cin >> table[i][j];
        }
    }
    
    D[0][0] = table[0][0]; D[0][1] = table[0][1]; D[0][2] = table[0][2];
    
    for (int k=1;k<N;k++) {
        D[k][0] = min(D[k-1][1], D[k-1][2]) + table[k][0];
        D[k][1] = min(D[k-1][0], D[k-1][2]) + table[k][1];
        D[k][2] = min(D[k-1][0], D[k-1][1]) + table[k][2];
    }
    
    cout << min(min(D[N-1][0], D[N-1][1]), D[N-1][2]) << "\n";

    return 0;
}