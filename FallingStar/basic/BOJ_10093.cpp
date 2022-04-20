#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, big, small;
    cin >> a >> b;
    small = (a < b)? a:b;
    big = (a > b)? a: b;
    if (big != small) cout << big - small - 1 << "\n";
    else cout << 0;
    for (long long i=small+1; i<big; i++) cout << i << " ";
    return 0;
}
