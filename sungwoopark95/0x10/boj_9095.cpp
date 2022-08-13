#include <iostream>
using namespace std;

int D[13];
int T, n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while (T--) {
        cin >> n;
        D[1] = 1, D[2] = 2, D[3] = 4;
        
        for (int k=4;k<=n;k++) {
            int sum = 0;
            for (int j=1;j<=3;j++) {
                sum += D[k-j];
            }
            D[k] = sum;
        }
        
        cout << D[n] << "\n";
    }

    
    return 0;
}