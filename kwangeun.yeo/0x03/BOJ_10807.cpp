#include <bits/stdc++.h>
using namespace std;

int N;
int v;
int freq[205];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        freq[num + 100]++;
    }
    cin >> v;
    cout << freq[v + 100];

    return 0;
}