#include <iostream>
using namespace std;

int N, K;
int facdp[12];

int Factorial(int x) {
    facdp[0] = 1;
    for (int i=1;i<=x;i++) {
        facdp[i] = i * facdp[i-1];
    }
    return facdp[x];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    cout << Factorial(N) / (Factorial(K)*Factorial(N-K)) << "\n";
    
    return 0;
}