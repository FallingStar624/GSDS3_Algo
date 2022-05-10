#include <bits/stdc++.h>

using namespace std;

deque<int> Deque;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string op;
        cin >> op;
        if (op == "push_front") {
            int x;
            cin >> x;
            Deque.push_front(x);
        } else if (op == "push_back") {
            int x;
            cin >> x;
            Deque.push_back(x);
        } else if (op == "pop_front") {
            if (!Deque.empty()) {
                cout << Deque.front() << '\n';
                Deque.pop_front();
            } else cout << "-1\n";
        } else if (op == "pop_back") {
            if (!Deque.empty()) {
                cout << Deque.back() << '\n';
                Deque.pop_back();
            } else cout << "-1\n";
        } else if (op == "size") {
            cout << Deque.size() << '\n';
        } else if (op == "empty") {
            if (Deque.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (op == "front") {
            if (!Deque.empty()) {
                cout << Deque.front() << '\n';
            } else cout << "-1\n";
        } else if (op == "back") {
            if (!Deque.empty()) {
                cout << Deque.back() << '\n';
            } else cout << "-1\n";
        }
    }

    return 0;
}