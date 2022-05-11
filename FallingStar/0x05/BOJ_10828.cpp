#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    int n, temp, i; cin >> n;
    stack<int> S;
    while (n--) {
        string code;
        cin >> code;
        if (code=="push") {
            cin >> temp;
            S.push(temp);
        } else if (code=="pop") {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if (code=="size") {
            cout << S.size() << '\n';
        } else if (code=="empty") {
            if (S.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
            }
        }
    }
    return 0;
}
