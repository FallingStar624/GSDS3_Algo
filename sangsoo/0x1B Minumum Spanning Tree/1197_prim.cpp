#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int v, e;
vector<pair<int, int>> adj[100005]; // {비용, 정점 번호}
//chk[i] : i번째 정점이 최소 신장 트리에 속해 있는가?

bool chk[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    // tuple<int, int, int> : {비용, 정점1, 정점 2}
    
    priority_queue<tuple<int, int, int>, vector <tuple<int, int, int>>, greater<tuple<int, int, int>> > pq; // 최소 힙
    chk[1] = 1; int cnt = 0; int ans = 0;
    for(auto nxt : adj[1]) pq.push({nxt.first, 1, nxt.second});
    while(cnt < v - 1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]){
            if(!chk[nxt.second]) pq.push({nxt.first, b, nxt.second});
        }
    }
    cout << ans;
}