#include <iostream>

using namespace std;

long long func(long long a, long long b, long long c) {
    if (b == 1) return a % c;
    long long tmp = func(a, b / 2, c);
    tmp = tmp * tmp % c;
    return (tmp * (b % 2 ? a : 1)) % c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c) << '\n';

    return 0;
}