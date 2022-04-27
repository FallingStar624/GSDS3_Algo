#include <bits/stdc++.h>

using namespace std;

stack< pair<int, int> > stk;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        int height;
        cin >> height;
        for (;;) {
            if (!stk.empty() && stk.top().first < height) {
                result += (i - stk.top().second);
                stk.pop();
            } else {
                stk.push({height, i});
                break;
            }
        }
    }
    while (!stk.empty()) {
        stk.pop();
        result += stk.size();
    }
    cout << result << '\n';

    return 0;
}