#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    int count[30];
    fill(count, count + 30, 0);

    cin >> s;
    for (char c: s) {
        count[c - 'a']++;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        cout << count[i - 'a'] << ' ';
    }

    return 0;
}