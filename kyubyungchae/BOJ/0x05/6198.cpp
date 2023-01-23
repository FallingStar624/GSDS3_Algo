#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int N;
    long long cnt = 0;

    cin >> N;

    int h;
    for(int i = 0; i < N; i++) {
        cin >> h;
        while(!st.empty() && h >= st.top())
            st.pop();
        cnt += st.size();
        st.push(h);
    }



    cout << cnt;

    return 0;
}