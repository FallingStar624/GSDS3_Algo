#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;
    int n;
    cin >> n;
    while (n--){
        string q;
        cin >> q;
        if (q == "push_back"){
            int val;
            cin >> val;
            dq.push_back(val);
        }
        else if (q == "push_front"){
            int val;
            cin >> val;
            dq.push_front(val);
        }
        else if (q == "pop_front"){
            if (dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (q == "pop_back"){
            if (dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (q == "front"){
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if (q == "back"){
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
        else if (q == "size"){
            cout << dq.size() << '\n';
        }
        else if (q == "empty"){
            cout << dq.empty() << '\n';
        }
    }
}