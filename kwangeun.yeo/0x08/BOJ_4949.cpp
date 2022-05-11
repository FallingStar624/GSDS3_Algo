#include <bits/stdc++.h>

using namespace std;

bool Balanced(string s, stack<char>& stk) {
    for (char c: s) {
        if (c == '(' || c == '[') stk.push(c);
        else if (c == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
        else if (c == ']') {
            if (stk.empty() || stk.top() != '[') return false;
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

    string s;
    for (;;) {
        getline(cin, s);
        if (s == ".") break;
        stack<char> stk;
        if (Balanced(s, stk)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}