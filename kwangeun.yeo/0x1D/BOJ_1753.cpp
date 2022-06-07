#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

#define MAXV (20010)
#define cost first
#define node second
#define INF (0x3f3f3f3f)

int d[MAXV];
vector<pair<int, int>> adj[MAXV];
priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    fill(d + 1, d + V + 1, INF);
    d[K] = 0;
    pq.push({0, K});
    while (!pq.empty()) {
        int cost, dst;
        tie(cost,dst) = pq.top(); pq.pop();
        if (d[dst] < cost) continue;
        for (auto next: adj[dst]) {
            if (d[next.node] > d[dst] + next.cost) {
                d[next.node] = d[dst] + next.cost;
                pq.push({d[next.node], next.node});
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}