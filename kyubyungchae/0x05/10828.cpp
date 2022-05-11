#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    while(n--) {
        string c;
        cin >> c;
        if(c == "push") {
            int t;
            cin >> t;
            st.push(t);
        } else if(c == "pop") {
            if(st.empty()) 
                cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if(c == "size") {
            cout << st.size() << '\n';
        } else if(c == "empty") {
            cout << (int)st.empty() << '\n';
        } else {
            if(st.empty()) 
                cout << -1 << '\n';
            else 
                cout << st.top() << '\n';
        }
    }


    return 0;
}