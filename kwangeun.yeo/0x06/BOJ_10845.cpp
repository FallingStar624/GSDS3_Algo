#include <bits/stdc++.h>

using namespace std;

queue<int> Q;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string op;
        cin >> op;
        if (op == "push") {
            int num;
            cin >> num;
            Q.push(num);
        } else if (op == "pop") {
            if (!Q.empty()) {
                cout << Q.front() << '\n';
                Q.pop();
            } else cout << "-1\n";
        } else if (op == "size") {
            cout << Q.size() << '\n';
        } else if (op == "empty") {
            if (Q.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (op == "front") {
            if (!Q.empty()) cout << Q.front() << '\n';
            else cout << "-1\n";
        } else if (op == "back") {
            if (!Q.empty()) cout << Q.back() << '\n';
            else cout << "-1\n";
        }
    }

    return 0;
}