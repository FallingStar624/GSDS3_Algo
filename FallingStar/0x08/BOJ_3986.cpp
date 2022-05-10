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
            } else if (c=='A' && S.top()=='A') {
                S.pop();
            } else if (c=='B' && S.top()=='B') {
                S.pop();
            } else {
                S.push(c);
            }
        }
        if (S.empty()) cnt++;
        while(!S.empty()) S.pop();
    }
    cout << cnt;
    return 0;
}

