#include <iostream>
#include <stack>

using namespace std;

#define MAX 1000000

int N;
stack<int> st;
int arr[MAX];
int ans[MAX];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = N - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i])
            st.pop();

        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }

    for (int i = 0; i < N; i++) cout << ans[i] << ' ';

    return 0;
}