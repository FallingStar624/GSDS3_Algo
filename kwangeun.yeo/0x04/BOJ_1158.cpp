#include <bits/stdc++.h>

using namespace std;

list<int> num;
int N, K;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        num.push_back(i);

    cout << "<";
    list<int>::iterator it = num.begin();
    for (;;) {
        for (int i = 0; i < K - 1; ++i) {
            if (++it == num.end()) it = num.begin();
        }
        cout << *it;
        it = num.erase(it);
        if (it == num.end()) it = num.begin();
        if (num.empty()) {
            cout << ">\n";
            break;
        } else {
            cout << ", ";
        }
    }

    return 0;
}