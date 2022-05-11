#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    int answer = 0;
    int tmp = 1;
    stack<int> stk;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(2);
            tmp *= 2;
        } else if (s[i] == '[') {
            stk.push(3);
            tmp *= 3;
        } else if (s[i] == ')') {
            if (stk.empty() || stk.top() != 2) { answer = 0; break; }
            if (s[i - 1] == '(') answer += tmp;
            stk.pop();
            tmp /= 2;
        } else if (s[i] == ']') {
            if (stk.empty() || stk.top() != 3) { answer = 0; break; }
            if (s[i - 1] == '[') answer += tmp;
            stk.pop();
            tmp /= 3;
        }
    }
    if (!stk.empty()) answer = 0;
    cout << answer << '\n';

    return 0;
}