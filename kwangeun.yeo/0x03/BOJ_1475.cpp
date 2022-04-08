#include <bits/stdc++.h>
using namespace std;

int N;
int freq[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    while (N) {
        freq[N % 10]++;
        N /= 10;
    }
    int max = (freq[6] + freq[9]);
    max = max % 2 ? ((max / 2) + 1) : (max / 2);
    for (int i = 0; i < 10; ++i) {
        if (i == 6 or i == 9) continue;
        if (max < freq[i]) max = freq[i];
    }
    cout << max;

    return 0;
}