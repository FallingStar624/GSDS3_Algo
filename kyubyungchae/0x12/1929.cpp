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

void printPrime(int start, int end) {

    for(int num = start; num <= end; num++) {
        if(isPrime(num))
            cout << num << '\n';
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    printPrime(m, n);

    return 0;
}