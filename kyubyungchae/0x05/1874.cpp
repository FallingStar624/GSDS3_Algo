#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> st;
    string output;

    cin >> n;

    int cnt = 1;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        while(cnt <= input) {
            st.push(cnt);
            cnt++;
            output += "+\n";
        }
        if(st.top() != input) {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        output += "-\n";
    }
    cout << output;

    return 0;
}