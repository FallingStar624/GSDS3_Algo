#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    int answer = 0;
    int bar = 0;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (i + 1 < s.size() && s[i+1] == ')') continue;
            else bar++;
        } else {
            if (i > 0 && s[i - 1] == '(') answer += bar;
            else { bar--; answer++; }
        }
    }
    cout << answer << '\n';

    return 0;
}