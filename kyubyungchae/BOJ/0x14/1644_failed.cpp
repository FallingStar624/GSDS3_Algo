#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n, sum;
int a[1000005];

bool isPrime(int num) {

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // Get prime numbers
    int p = 1;
    for(int i = 2; i <= n; i++) {
        if(isPrime(i))
            a[p++] = i;
    }

    // Partial sum
    for(int i = 1; i <= p; i++) {
        // cout << a[i] << " ";
        a[i] += a[i-1];
    }

    int st = 0, en = 0;
    int cnt = 0;


    while (en < p) {
        int csum = a[en] - a[st];
        if(csum <= n) {
            if(csum == n)
                cnt++;
            en++;
        }
        else 
            st++;
    }

    cout << cnt;

    return 0;
}