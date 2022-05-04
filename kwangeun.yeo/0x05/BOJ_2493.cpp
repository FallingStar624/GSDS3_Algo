#include <bits/stdc++.h>

using namespace std;

stack< pair<int, int> > stk;
string result;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    for (int tower_num = 1; tower_num <= N; ++tower_num) {
        int tower_height;
        cin >> tower_height;
        for (;;) {
            if (stk.empty()) {
                result += "0 ";
                stk.push({tower_height, tower_num});
                break;
            }
            if (stk.top().first > tower_height) {
                result += (to_string(stk.top().second) + " ");
                stk.push({tower_height, tower_num});
                break;
            } else {
                stk.pop();
            }
        }
    }

    cout << result << '\n';

    return 0;
}