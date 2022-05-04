#include <bits/stdc++.h>

using namespace std;

stack<unsigned int> stk;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    unsigned int result = 0;
    for (int i = 0; i < N; ++i) {
        unsigned int height;
        cin >> height;
        for (;;) {
            if (stk.empty()) {
                stk.push(height);
                break;
            } else if (stk.top() > height) {
                result += static_cast<unsigned int>(stk.size());
                stk.push(height);
                break;
            } else {
                stk.pop();
            }
        }
    }
    cout << result << '\n';

    return 0;
}