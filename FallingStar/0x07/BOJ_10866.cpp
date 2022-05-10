#include <iostream>
#include <deque>
using namespace std;

deque<int> deq;
int n, i, tmp;
string cmd;

int main() {
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> tmp;
            deq.push_front(tmp);
        } else if (cmd =="push_back") {
            cin >> tmp;
            deq.push_back(tmp);
        } else if (cmd == "pop_front") {
            tmp = deq.empty() ? -1: deq.front();
            cout << tmp << '\n';
            if (tmp != -1) deq.pop_front();
        } else if (cmd == "pop_back") {
            tmp = deq.empty() ? -1 : deq.back();
            cout << tmp << '\n';
            if (tmp != -1) deq.pop_back();
        } else if (cmd == "size") {
            cout << deq.size() << '\n';
        } else if (cmd == "empty") {
            cout << deq.empty() << '\n';
        } else if (cmd == "front") {
            tmp = deq.empty() ? -1 : deq.front();
            cout << tmp << '\n';
        } else {
            tmp = deq.empty() ? -1 : deq.back();
            cout << tmp << '\n';
        }
    }
}

