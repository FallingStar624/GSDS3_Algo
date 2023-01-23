#include <iostream>
#include <math.h>

using namespace std;

bool primes[10000001];

bool isPrime(int num) {

    if(num <= 1)
        return false;

    if(primes[num])
        return true;

    for(int div = 2; div <= sqrt(num); div++) {
        if(num % div == 0) {
            return false;
        }
    }
    primes[num] = true;
    return true;
}

void printPrimeFactor(int num) {

    if(num == 1)
        return;
    
    while(num > 1) {

        for(int div = 2; div <= num; div++) {

            if(!isPrime(div)) 
                continue;

            if(num % div == 0) {
                cout << div << '\n';
                num /= div;
                break;
            }
        }
    }

}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    printPrimeFactor(n);

    return 0;
}