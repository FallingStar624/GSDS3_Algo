#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    stack<int> st;

    cin >> K;

    for(int i = 0; i < K; i++) {
        int input;
        cin >> input;
        if(input == 0) {
            st.pop();
        } else {
            st.push(input);
        }
    }
    int sum = 0;
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum;


    return 0;
}