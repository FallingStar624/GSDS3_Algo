#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=1; i<N+1; i++) {
        for (int k=0; k<N-i; k++) {
            cout << " ";
        }
        for (int j=0; j<i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
