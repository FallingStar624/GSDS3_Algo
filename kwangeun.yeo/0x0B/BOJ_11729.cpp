#include <iostream>

using namespace std;

void func(int n, int src, int dst) {
    if (n == 0) return;
    func(n - 1, src, 6 - src - dst);
    cout << src << ' ' << dst << '\n';
    func(n - 1, 6 - src - dst, dst);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    func(n, 1, 3);

    return 0;
}