#include <stack>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int N;
stack<pair<int,int>> st;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    st.push({100000001, 0});
    for(int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        while(st.top().first < height)
            st.pop();
        cout << st.top().second << " ";
        st.push({height, i});
    }
    
    return 0;
}