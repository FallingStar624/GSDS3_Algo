#include <bits/stdc++.h>
using namespace std;

void func(int cards[], int a, int b) {
    int rev[20];
    for (int i = 0; i < b - a + 1; ++i) {
        rev[i] = cards[b - i];
    }
    for (int i = a; i <= b; ++i) {
        cards[i] = rev[i - a];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cards[20];
    int a, b;

    for (int i = 0; i < 20; ++i) {
        cards[i] = i + 1;
    }
    for (int i = 0; i < 10; ++i) {
        cin >> a >> b;
        func(cards, a - 1, b - 1);
    }
    for (int i = 0; i < 20; ++i) {
        cout << cards[i] << ' ';
    }

    return 0;
}
