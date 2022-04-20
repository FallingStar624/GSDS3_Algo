#include <iostream>
#include <string>
#include <list>
using namespace std;


int main() {
    string str;
    cin >> str;
    list<char> editor(str.begin(), str.end());
    auto cursor = editor.end();
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        char input;
        cin >> input;
        if (input == 'L') {
            if (cursor != editor.begin()) {
                cursor--;
            }
        } else if (input == 'D') {
            if (cursor != editor.end()){
                cursor++;
            }
        } else if (input == 'B') {
            if (cursor != editor.begin()) {
                cursor = editor.erase(--cursor);
            }
        } else {
            char target;
            cin >> target;
            editor.insert(cursor, target);
        }
    }
    for (char c: editor) {
        cout << c;
    }
    return 0;
}
