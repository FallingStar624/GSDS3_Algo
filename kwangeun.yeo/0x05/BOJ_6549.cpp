#include <bits/stdc++.h>

using namespace std;

stack< pair<long long, long long> > stk;

long long GetMaxArea(int N) {
    long long max_area = 0;
    for (int i = 0; i < N; ++i) {
        long long height;
        cin >> height;
        for (;;) {
            if (!stk.empty() && stk.top().first > height) {
                long long width = static_cast<long long>(i) - stk.top().second;
                max_area = max(max_area, stk.top().first * width);
                stk.pop();
            } else {
                stk.push({height, static_cast<long long>(i)});
                break;
            }
        }
    }
    if (!stk.empty()) {
        max_area = max(max_area, stk.top().first * static_cast<long long>(stk.size()));
    }
    return max_area;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    for (;;) {
        int N;
        cin >> N;
        if (N == 0) break;
        while (!stk.empty()) stk.pop();
        cout << GetMaxArea(N) << '\n';
    }

    return 0;
}