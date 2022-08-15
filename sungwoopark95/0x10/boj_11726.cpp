#include <iostream>
using namespace std;

int D[1003];
int T, n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    D[1] = 1, D[2] = 2;
    
    for (int k=3;k<=n;k++) {
        int sum = 0;
        for (int j=1;j<=2;j++) {
            sum += D[k-j];
        }
        D[k] = sum % 10007;
    }
    
    cout << D[n] << "\n";
    
    return 0;
}