#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체를 사용하여 소수를 구하는 함수
vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // N까지의 소수를 구함
    vector<int> primes = getPrimes(N);

    int count = 0;
    int sum = 0;
    int left = 0;
    int right = 0;

    // 투 포인터를 사용하여 연속된 소수의 합을 구함
    while (true) {
        if (sum >= N) {
            sum -= primes[left++];
        } else if (right == primes.size()) {
            break;
        } else {
            sum += primes[right++];
        }

        if (sum == N) {
            count++;
        }
    }

    cout << count;

    return 0;
}