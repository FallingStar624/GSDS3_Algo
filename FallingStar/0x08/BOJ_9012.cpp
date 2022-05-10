#include <iostream>
#include <stack>
using namespace std;

int n, cnt;
stack<char> S;
string line;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> line;
        for (char c: line) {
            if (S.empty()) {
                S.push(c);
            } else if (c==')' && S.top()=='(') {
                S.pop();
            } else {
                S.push(c);
            }
        }
        if (S.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        while(!S.empty()) S.pop();
    }
    return 0;
}

