#include <bits/stdc++.h>

using namespace std;

stack<int> stack_;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string order;
        cin >> order;
        if (order == "push") {
            int n;
            cin >> n;
            stack_.push(n);
        } else if (order == "pop") {
            if (stack_.empty()) cout << "-1\n";
            else {
                cout << stack_.top() << '\n';
                stack_.pop();
            }
        } else if (order == "size") {
            cout << stack_.size() << '\n';
        } else if (order == "empty") {
            if (stack_.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (order == "top") {
            if (stack_.empty()) cout << "-1\n";
            else cout << stack_.top() << '\n';
        }
    }

    return 0;
}