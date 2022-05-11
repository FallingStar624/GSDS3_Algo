#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        
        stack<char> st;
        
        for(auto c : input) {
            if(st.empty() || c != st.top()) {
                st.push(c);
            } else {
                st.pop();
            }
        }

        if(st.empty())
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}