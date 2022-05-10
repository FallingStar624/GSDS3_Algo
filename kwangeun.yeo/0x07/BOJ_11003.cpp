#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(pair<int,int> p1, pair<int,int> p2) { return p1.first > p2.first; }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, L;
    string answer = "";
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        int start = i - L + 1;
        start = (start < 0) ? 0 : start;
        pq.push({num, i});
        for (;!(pq.top().second >= start && pq.top().second <= i);) {
            pq.pop();
        }
        answer += (to_string(pq.top().first) + " ");
    }
    cout << answer;

    return 0;
}