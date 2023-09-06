// check basics again....
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
using namespace std;

int V, E, u, v, w;
int dist[801];
vector<pair<int, int>> edges[801];

int dijkstra(int st, int en) {
    priority_queue<pair<int, int>> pq;
    for (int i=0; i<=V; i++) dist[i] = INF;
    dist[st] = 0;
    pq.push(make_pair(0, st));
    while(!pq.empty()) {
        int curr = pq.top().second;
        int c_dist = -pq.top().first;
        pq.pop();
        if (c_dist > dist[curr]) continue;
        for (int i = 0; i < edges[curr].size(); i++) {
            int next = edges[curr][i].first;
            int n_dist = c_dist + edges[curr][i].second;
            if (n_dist < dist[next]) {
                dist[next] = n_dist;
                pq.push(make_pair(-n_dist, next));
            }
        }
    }
    return dist[en];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    cin >> u >> v;
    int ans1 = dijkstra(1,u) + dijkstra(u, v) + dijkstra(v, V);
    if (u==1 && v ==V) ans1= dijkstra(1, V);
    int ans2 = dijkstra(1,v) + dijkstra(v, u) + dijkstra(u, V);
    if (ans1 >= INF && ans2 >= INF) cout << -1;
    else cout << min(ans1, ans2);
    return 0;
}
