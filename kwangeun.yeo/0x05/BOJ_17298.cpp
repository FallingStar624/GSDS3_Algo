#include <bits/stdc++.h>

using namespace std;

stack< pair<int, int> > candidate;
int NGE[1000010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    fill(NGE, NGE + N, -1);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        for (;;) {
            if (candidate.empty()) {
                candidate.push({num, i});
                break;
            } else if (candidate.top().first < num) {
                NGE[candidate.top().second] = num;
                candidate.pop();
            } else {
                candidate.push({num, i});
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << NGE[i] << ' ';
    }
    cout << '\n';

    return 0;
}