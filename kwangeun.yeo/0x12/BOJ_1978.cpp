#include <iostream>
using namespace std;

int is_prime(int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    int num;
    int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        cnt += is_prime(num);
    }
    cout << cnt;

    return 0;
}