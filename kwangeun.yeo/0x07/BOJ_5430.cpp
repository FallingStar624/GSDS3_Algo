#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

void func() {
    string p, arr;
    int _;
    cin >> p >> _ >> arr;
    int input_num;
    for (char c : arr) {
        if (c == '[') input_num = 0;
        else if (c == ',' || c == ']') {
            if (input_num) dq.push_back(input_num);
            input_num = 0;
        }
        else input_num = input_num * 10 + c - '0';
    }

    int n_r = 0;
    for (char op : p) {
        if (op == 'R') n_r++;
        else if (dq.empty()) { cout << "error"; return; }
        else if (n_r % 2) dq.pop_back();
        else dq.pop_front();
    }
    cout << '[';
    while (dq.size() > 1) {
        int num;
        if (n_r % 2) {
            num = dq.back();
            dq.pop_back();
        } else {
            num = dq.front();
            dq.pop_front();
        }
        cout << num << ',';
    }
    if (!dq.empty()) cout << dq.front();
    cout << ']';
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        dq.clear();
        func();
        cout << '\n';
    }

    return 0;
}