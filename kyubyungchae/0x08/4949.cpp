#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        string a;
        getline(cin, a);
        if(a == ".")
            break;
        
        stack<char> st;
        bool isValid = true;
        for(auto c : a) {
            if(c == '(' || c == '[') {
                st.push(c);
            } else if(c == ')') {
                if(st.empty() || st.top() != '(') {
                    isValid = false;
                    break;
                }
                st.pop();
            } else if(c == ']') {
                if(st.empty() || st.top() != '[') {
                    isValid = false;
                    break;
                }
                st.pop();               
            }
        }
        if(!st.empty())
            isValid = false;
        
        if(isValid)
            cout << "yes\n";
        else
            cout << "no\n";

    }

    return 0;
}