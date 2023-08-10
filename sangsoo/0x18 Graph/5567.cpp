#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[502];
int vis[502];
int lv[502];
int bfs(int v, int mx_lv){ // v: 시작노드(이문제에서는 1), mx_lv : 최대 lv(이문제에서는 2)
    int cnt = 0;
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    lv[v] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            if (lv[cur] == mx_lv) return cnt;
            vis[nxt] = 1; cnt++;
            q.push(nxt);
            lv[nxt] = lv[cur] + 1;
        }
    }   
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << bfs(1, 2);
}