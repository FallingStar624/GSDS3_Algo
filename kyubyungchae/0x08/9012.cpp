#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string ps;
        cin >> ps;

        stack<char> st;
        bool isValid = true;
        for(auto c : ps) {
            if(c == '(') {
                st.push(c);
            } else {
                if(st.empty()) {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if(!st.empty())
            isValid = false;

        if(isValid)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}