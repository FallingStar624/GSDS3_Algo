#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=0; i<N+1; i++) {
        for (int j=N-i; j>0; j--) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}

