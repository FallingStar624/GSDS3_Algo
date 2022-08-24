#include <iostream>
using namespace std;

int D[1003];
int T, n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    D[1] = 1, D[2] = 3;
    
    for (int k=3;k<=n;k++) {
        int sum = 0;
        sum += (2*D[k-2])+D[k-1];
        D[k] = sum % 10007;
    }
    
    cout << D[n] << "\n";
    
    return 0;
}