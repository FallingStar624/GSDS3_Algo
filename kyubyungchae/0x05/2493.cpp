#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int N;

    cin >> N;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int h;
        cin >> h;
        
        while(!st.empty() && st.top() <= h)
            st.pop();
        
        cnt += st.size();
        st.push(h);
        cout << cnt << " ";
    }
    
    return 0;
}