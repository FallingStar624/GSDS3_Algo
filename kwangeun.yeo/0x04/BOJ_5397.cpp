#include <bits/stdc++.h>

using namespace std;

int T;
list<char> passwd;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t = 0; t < T; ++t) {
        passwd = {};
        string ops;
        cin >> ops;

        list<char>::iterator cursor = passwd.begin();
        for (char op: ops) {
            switch (op) {
                case '<':
                    if (cursor != passwd.begin()) cursor--;
                    break;
                case '>':
                    if (cursor != passwd.end()) cursor++;
                    break;
                case '-':
                    if (cursor != passwd.begin()) {
                        cursor--;
                        cursor = passwd.erase(cursor);
                    }
                    break;
                default:
                    passwd.insert(cursor, op);
                    break;
            }
        }

        for (char c: passwd) cout << c;
        cout << '\n';
    }

    return 0;
}