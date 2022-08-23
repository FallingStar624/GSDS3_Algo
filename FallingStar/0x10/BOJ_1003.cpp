#include <iostream>
using namespace std;
int T,N;
int zeros[41];
int ones[41];

void fibo(int n) {
    zeros[n] = zeros[n-1] + zeros[n-2];
    ones[n] = ones[n-1] + ones[n-2];
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    zeros[0]=1;
    ones[1]=1;
    for (int i=2; i<41; i++) {
        fibo(i);
    }
    cin >> T;
    for (int tc=0; tc<T; tc++) {
        cin >> N;
        cout << zeros[N] << " " << ones[N] << "\n";
    }
    return 0;
}
