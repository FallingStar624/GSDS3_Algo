#include <bits/stdc++.h>

using namespace std;

bool empty_[52];

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int front = 1;
    int sum = 0;
    for (int i = 0; i < M; ++i) {
        int target;
        int cursor;
        int op2 = 0;
        int op3 = 1;
        cin >> target;
        cursor = front;
        while (cursor != target) {
            if (++cursor > N) cursor = 1;
            if (!empty_[cursor]) op2++;
        }
        while (true) {
            if (++cursor > N) cursor = 1;
            if (!empty_[cursor]) break;
        }
        int next_front = cursor;
        while (cursor != front) {
            if (++cursor > N) cursor = 1;
            if (!empty_[cursor]) op3++;
        }
        sum += min(op2, op3);
        empty_[target] = true;
        front = next_front;
    }
    cout << sum << '\n';

    return 0;
}