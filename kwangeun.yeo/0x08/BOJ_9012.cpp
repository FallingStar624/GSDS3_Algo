#include <bits/stdc++.h>

using namespace std;

bool VPS(string s, stack<char>& stk) {
    for (char c: s) {
        if (c == '(') stk.push(c);
        else {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
    }
    if (stk.empty()) return true;
    else return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;

        stack<char> stk;
        if (VPS(s, stk)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}