#include <iostream>
#include <string>
#include <list>
using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        list<char> result;
        auto cursor = result.begin();
        for (char c: str) {
            if (c == '<') {
                if (cursor != result.begin()) {
                    cursor--;
                }
            } else if (c == '>') {
                if (cursor != result.end()) {
                    cursor++;
                }
            } else if (c == '-') {
                if (cursor != result.begin()) {
                    cursor = result.erase(--cursor);
                }
            } else {
                result.insert(cursor, c);

            }
        }
        for (char c : result) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
