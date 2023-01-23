#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    deque<int> dq;

    while(N--) {
        string oper;
        cin >> oper;
        
        if(oper == "push_back") {
            int n;
            cin >> n;
            dq.push_back(n);
        } else if(oper == "push_front") {
            int n;
            cin >> n;
            dq.push_front(n);
        } else if(oper == "front") {
            if(!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << -1 << '\n';
        } else if(oper == "back") {
            if(!dq.empty())
                cout << dq.back() << '\n';
            else
                cout << -1 << '\n';

        } else if(oper == "size") {
            cout << dq.size() << '\n';

        } else if(oper == "empty") {
            cout << (int)dq.empty() << '\n';

        } else if(oper == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }

        } else if(oper == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << -1 << '\n';
            }            

        } else {
            cout << "Enter Correct OPER\n";
        }
    }
    

    return 0;
}