#include <iostream>
using namespace std;

long long func(long long num, long long div) {
    long long cnt = 0;
    for (long long down = div; num >= down; down *= div) {
        cnt += (num / down);
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    long long n, m;
    cin >> n >> m;
    long long two = func(n, 2) - func(m, 2) - func(n - m, 2);
    long long five = func(n, 5) - func(m, 5) - func(n - m, 5);
    cout << min(two, five);

    return 0;
}