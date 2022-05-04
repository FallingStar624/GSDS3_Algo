#include <bits/stdc++.h>

using namespace std;

stack<int> mystack;
vector<char> result;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int next_num = 1;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (;;) {
            if (!mystack.empty() && mystack.top() > num) {
                cout << "NO\n";
                return 0;
            }
            if (!mystack.empty() && mystack.top() == num) {
                result.push_back('-');
                mystack.pop();
                break;
            }
            else {
                result.push_back('+');
                mystack.push(next_num++);
            }
        }
    }
    for (char c : result) cout << c << '\n';

    return 0;
}