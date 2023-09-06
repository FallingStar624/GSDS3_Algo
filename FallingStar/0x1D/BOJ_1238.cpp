#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int V, E, st, u, v, w;
int dist[1001];
int tmp_dist[1001];
vector<pair<int, int>> edges[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> st;
    for (int i=0; i<=V; i++) dist[i] = INF;
    dist[st] = 0;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
    }
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, st));
    while(!pq.empty()) {
        int curr = pq.top().second;
        int c_dist = -pq.top().first;
        pq.pop();
        if (c_dist > dist[curr]) continue;
        for (int i=0; i<edges[curr].size(); i++) {
            int next = edges[curr][i].first;
            int n_dist = c_dist + edges[curr][i].second;
            if (n_dist < dist[next]) {
                dist[next] = n_dist;
                pq.push(make_pair(-n_dist, next));
            }
        }
    }
    for (int i=1; i<V+1; i++) {
        if (i==st) continue;
        for (int i=0; i<=V; i++) tmp_dist[i] = INF;
        tmp_dist[i] = 0;
        pq.push(make_pair(0, i));
        while(!pq.empty()) {
            int curr = pq.top().second;
            int c_dist = -pq.top().first;
            pq.pop();
            if (c_dist > tmp_dist[curr]) continue;
            for (int i=0; i<edges[curr].size(); i++) {
                int next = edges[curr][i].first;
                int n_dist = c_dist + edges[curr][i].second;
                if (n_dist < tmp_dist[next]) {
                    tmp_dist[next] = n_dist;
                    pq.push(make_pair(-n_dist, next));
                }
            }
        }
        dist[i] += tmp_dist[st];
    }
    int ans = 0;
    for (int i=1; i<V+1; i++) ans = max(ans, dist[i]);
    cout << ans;
    return 0;
}
