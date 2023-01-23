#include <iostream>
#include <math.h>

using namespace std;

/*
n < x <= 2n
Prime
*/

int d[1000000];

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

int countPrime(int start, int end) {

    int cnt = 0;

    for(int num = start + 1; num <= end; num++) {
        if(isPrime(num))
            cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {6
    
        int n;
        cin >> n;

        if(n == 0)
            break;
        
        for(int i = 1; i <= n; i++) {

        }

        cout << d[n] << '\n';

    }

    return 0;
}