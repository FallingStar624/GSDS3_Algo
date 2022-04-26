#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, i, j, key, current; cin >> n;
    stack<int> S;
    string result = "";
    current = 1;
    S.push(100001);
    for (i=0; i<n; i++) {
        cin >> key;
        while (S.top() != key) {
            if (current > n) {
                cout << "NO";
                return 0;
            }
            S.push(current);
            current++;
            result += "+";
        }
        if (S.size() > 100000) {
            cout << "NO";
            return 0;
        }
        if (S.top() == key) {
            S.pop();
            result += "-";
        }
    }
    for (char c: result) {
        cout << c << '\n';
    }
}
