#include <iostream>
#include <math.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int div = 2; div <= sqrt(n); div++) {
        while(n % div == 0) {
            cout << div << '\n';
            n /= div;
        }
    }
    if(n != 1)
        cout << n;

    return 0;
}