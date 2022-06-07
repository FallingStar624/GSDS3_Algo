#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define MAXV (10005)

using namespace std;
int V, E;
int cnt = 0;
int sum = 0;
bool chk[MAXV];
vector<pair<int, int>> adj[MAXV]; // cost, dst
priority_queue<tuple<int, int, int>, // cost, src, dst
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> pq;


int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> V >> E;
    int a, b, c;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    chk[a] = true; cnt++;
    for (auto nxt: adj[a]) {
        pq.push({nxt.first, a, nxt.second});
    }
    while (cnt < V) {
        int src, dst, cost;
        tie(cost, src, dst) = pq.top(); pq.pop();

        if (chk[dst]) continue;
        chk[dst] = true; cnt++; sum += cost;
        for (auto nxt: adj[dst]) {
            if (chk[nxt.second]) continue;
            pq.push({nxt.first, dst, nxt.second});
        }
    }
    cout << sum;

    return 0;
}