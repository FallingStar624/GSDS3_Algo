#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string str; int commands;
    cin >> str >> commands;

    list<char> L;
    for (int i=0;i<(int)str.length();i++) {
        char c = str[i];
        L.push_back(c); // cursor를 뒤로 이동시키면서 push
    }
    list<char>::iterator cursor = L.end();

    for (int i=0;i<commands;i++) {
        char op;
        cin >> op;
        if (op == 'P') {
            char insert;
            cin >> insert;
            L.insert(cursor, insert); // cursor를 반환하게 되면 cursor는 추가해도 이동하지 않음
        } else if (op == 'L') {
            if (cursor != L.begin()) {
                cursor--;
            }
        } else if (op == 'D') {
            if (cursor != L.end()) {
                cursor++;
            }
        } else {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor); // erase의 경우 cursor를 반환하지 않으면 cursor가 같이 이동하지 않음 - segmentation fault 가능!
            }
        }
    }

    list<char>::iterator itr;
    for (itr=L.begin();itr!=L.end();itr++) {
        cout << *itr << "";
    }
    cout << "\n";

    return 0;
}