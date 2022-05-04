#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int N;
stack<pair<int,int>> st;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long ans = 0;

    while(N--) {
        int height;
        cin >> height;
        int cnt = 1;

        while(!st.empty() && st.top().first <= height) {
            ans += st.top().second;
            if(st.top().first == height)
                cnt += st.top().second;
            st.pop();
        }
        if(!st.empty())
            ans++;
        st.push({height, cnt});
    }

    cout << ans;

    return 0;
}