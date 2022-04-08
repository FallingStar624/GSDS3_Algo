#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int freq[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> A >> B >> C;
    int num = A * B * C;
    while (num) {
        freq[num % 10]++;
        num /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        cout << freq[i] << '\n';
    }

    return 0;
}