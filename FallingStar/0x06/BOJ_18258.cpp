#include <iostream>
#include <queue>
using namespace std;

int n, i, tmp;
queue<int> Q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    string command;
    for (i=0; i<n; i++) {
        cin >> command;
        if (command == "push") {
            cin >> tmp;
            Q.push(tmp);
        }  else if (command == "pop") {
            if (Q.empty()) {
                cout << -1 << "\n";
            } else {
                tmp = Q.front();
                Q.pop();
                cout << tmp << "\n";
            }
        } else if (command == "size") {
            cout << Q.size() << "\n";
        } else if (command == "empty") {
            cout << int(Q.empty()) << "\n";
        } else if (command == "front") {
            if (Q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << Q.front() << "\n";
            }
        } else {
            if (Q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << Q.back() << "\n";
            }
        }
    }
    return 0;
}

