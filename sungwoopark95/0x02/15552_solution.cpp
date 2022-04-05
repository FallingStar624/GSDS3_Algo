#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long T; int A, B; 
    cin >> T;

    for (int i=0;i<T;i++) {
        cin >> A >> B;
        cout << A + B << '\n';
    }

    return 0;
}