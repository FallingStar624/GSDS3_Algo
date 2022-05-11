#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    string s;
    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        stack<char> stk;
        for (char c : s) {
            if (stk.empty() || stk.top() != c) stk.push(c);
            else stk.pop();
        }
        if (stk.empty()) answer++;
    }
    cout << answer << '\n';

    return 0;
}