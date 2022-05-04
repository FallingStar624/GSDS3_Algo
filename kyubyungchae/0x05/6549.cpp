#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;

        stack<pair<int,int>> st;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int h;
            cin >> h;
            int idx = i;
            while(!st.empty() && st.top().first >= h) {
                ans = max(ans, 1LL * (i - st.top().second) * st.top().first);
                idx = st.top().second;
                st.pop();
            }
            st.push({h, idx});
        }
        while(!st.empty()) {
            ans = max(ans, 1LL * (n - st.top().second) * st.top().first);
            st.pop();
        }
        cout << ans << '\n';
    }

    return 0;
}