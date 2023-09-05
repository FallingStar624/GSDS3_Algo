#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int v, e, st, en;

vector<pair<int, int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d[1005]; // 최단 거리 테이블
int pre[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    fill(d, d+v+1, INF);
    while(e--){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b}); // w: a에서 b로가는 cost(weight)
    }
    cin >> st >> en;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[st] = 0;
    pq.push({d[st], st}); // 우선순위 큐에 (0, 시작점) 추가
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << '\n';
    vector<int> path;
    int cur = en;
    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(auto x : path) cout << x << ' ';
}

