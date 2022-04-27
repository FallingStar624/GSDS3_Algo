#include <bits/stdc++.h>

using namespace std;

stack<int> account;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        unsigned int money;
        cin >> money;
        if (money == 0) account.pop();
        else account.push(money);
    }
    unsigned int money_sum = 0;
    while (!account.empty()) {
        money_sum += account.top();
        account.pop();
    }
    cout << money_sum << '\n';

    return 0;
}