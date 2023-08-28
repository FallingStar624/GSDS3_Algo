#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <functional>    // greater, less

using namespace std;

int v, e;
vector<pair<int,int>> adj[10005]; // (비용, 노드 번호)

bool chk[10005]; // i번째 정점이 최소 신장 트리에 속해있는가?

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for(int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    int cnt = 0; // 현재 선택된 간선의 수
    int ans = 0;

    // tuple<int,int,int> : {비용, 정점 1, 정점 2}
    priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>> > pq;
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second});
    
    while(cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;

        ans += cost;
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.second])
                pq.push({nxt.first, b, nxt.second});
        }
    }
    cout << ans;



    return 0;
}

