#include <iostream>
#include <math.h>
using namespace std;

int N, max_elmnt, idx, sum;
int hash_table[1002];
int primes[1002];

bool IsPrime(int x) {
    if (x == 1) { return false; }
    double x_sqrt = sqrt(x);
    for (int i=2;i<=x_sqrt;i++) {
        if (x % i == 0) { return false; }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    // make a hash table
    for (int i=1;i<=N;i++) {
        int temp;
        cin >> temp;
        hash_table[temp]++;
        if (max_elmnt < temp) { max_elmnt = temp; }
    }
    
    // make a prime number table until the max_element
    for (int i=1;i<=max_elmnt;i++) {
        if (IsPrime(i)) { primes[idx++] = i; }
    }
    
    for (int i=0;i<idx;i++) {
        sum += hash_table[primes[i]];
    }
    cout << sum << "\n";

    return 0;
}