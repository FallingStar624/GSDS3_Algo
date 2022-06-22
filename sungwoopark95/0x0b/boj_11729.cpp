#include <bits/stdc++.h>
using namespace std;

void hanoi(int A, int B, int num) {
    if (num == 1) {
        cout << A << " " << B << "\n";
        return;
    } else {
        hanoi(A, 6-A-B, num-1);
        cout << A << " " << B << "\n";
        hanoi(6-A-B, B, num-1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    long long cnt = pow(2, N) - 1;
    cout << cnt << "\n";
    hanoi(1, 3, N);
    
    return 0;
}