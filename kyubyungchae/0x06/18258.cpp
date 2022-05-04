#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;
    while(n--) {
        string c;
        cin >> c;
        if(c == "push") {
            int t;
            cin >> t;
            q.push(t);
        } else if(c == "pop") {
            if(q.empty()) 
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(c == "size") {
            cout << q.size() << '\n';
        } else if(c == "empty") {
            cout << (int)q.empty() << '\n';
        } else if(c == "front") {
            if(q.empty()) 
                cout << -1 << '\n';
            else 
                cout << q.front() << '\n';
        } else { // back
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }


    return 0;
}