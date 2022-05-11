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
    int sum = 0;
    int num = 1;

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '(') {
            num *= 2;
            st.push(input[i]);
        } else if(input[i] == '[') {
            num *= 3;
            st.push(input[i]);
        } else if(input[i] == ')') {
            if(st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if(input[i-1] == '(')
                sum += num;
            st.pop();
            num /= 2;
        } else {
            if(st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if(input[i-1] == '[')
                sum += num;
            st.pop();
            num /= 3;
        }
    }
    if(st.empty())
        cout << sum;
    else
        cout << 0;

    return 0;
}