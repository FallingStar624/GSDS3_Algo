#include <bits/stdc++.h>

using namespace std;

list<char> text;
list<char>::iterator cursor;
int M;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cursor = text.begin();
    string tmp;
    cin >> tmp;
    for (char c : tmp) text.insert(cursor, c);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        char operation;
        cin >> operation;
        switch (operation) {
            case 'L':
                if (cursor != text.begin()) cursor--;
                break;
            case 'D':
                if (cursor != text.end()) cursor++;
                break;
            case 'B':
                if (cursor != text.begin()) cursor = text.erase(--cursor);
                break;
            case 'P':
                char c;
                cin >> c;
                text.insert(cursor, c);
                break;
            default:
                break;
        }
    }
    for (char c : text) cout << c;

    return 0;
}