#include <iostream>
#include <algorithm>
using namespace std;

int N;
int rope[100010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> rope[i];
    }
    sort(rope, rope + N, greater<int>());
    int weight = 0;
    for (int i = 0; i < N; ++i) {
        weight = max(weight, rope[i] * (i + 1));
    }
    cout << weight;

    return 0;
}