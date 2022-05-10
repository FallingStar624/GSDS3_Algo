#include <iostream>
#include <stack>
using namespace std;

int i, cnt=0;
char pre = 'a';
stack<char> S;
string line;

int main() {
    cin >> line;
    for (char c: line) {
        if (S.empty()) {
            S.push(c);
        } else if (c==')' && pre=='(') {
            cnt += S.size()-1;
            S.pop();
        } else if (c==')' && pre==')') {
            cnt++;
            S.pop();
        } else {
            S.push(c);
        }
        pre = c;
    }
    cout << cnt;
    return 0;
}

