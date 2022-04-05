#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=1; i <2*N; i++) {
        for (int j=0; j<(i<=N? i-1:2*N-i-1); j++) cout << " ";
        for (int k=0; k<(i<=N? 2*N-2*i+1:2*(i-N)+1); k++) cout << "*";
        cout << "\n";
    }
    return 0;
}
