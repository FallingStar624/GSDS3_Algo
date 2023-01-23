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
    int isDirect = 0;

    for(auto c : input) {

        if(c == '(') {
            st.push(c);
            isDirect = 1;
        } else if(c == ')' && st.top() == '(') {
            st.pop();
            if(isDirect) {
                cnt += (int)st.size();
                isDirect = 1 - isDirect;
            } else {
                cnt += 1;
            }
        } else {
            st.pop();
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}

