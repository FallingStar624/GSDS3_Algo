#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    stack<char> st;
    int cnt = 0;

    for(auto c : input) {
        if(c == '(') {
            st.push(c);
        } else if(c == ')' && st.top() == '(') {
            st.pop();
            cnt += (int)st.size();
        } else {
            st.pop();
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}