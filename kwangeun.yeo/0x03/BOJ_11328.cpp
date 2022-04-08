#include <bits/stdc++.h>
using namespace std;

int T;
string s1, s2;
int w1[30];
int w2[30];

string is_strfry() {
    fill(w1, w1 + 30, 0);
    fill(w2, w2 + 30, 0);
    cin >> s1 >> s2;
    for (char c: s1) w1[c - 'a']++;
    for (char c: s2) w2[c - 'a']++;

    for (int w = 'a'; w <= 'z'; ++w) {
        if (w1[w - 'a'] != w2[w - 'a']) return "Impossible";
    }
    return "Possible";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << is_strfry() << '\n';
    }

    return 0;
}
