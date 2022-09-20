#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num) {

    if(num <= 1)
        return false;

    for(int div = 2; div <= sqrt(num); div++) {
        if(num % div == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    while(n--) {
        int num;
        cin >> num;

        if(isPrime(num))
            ans++;

    }

    cout << ans;

    return 0;
}