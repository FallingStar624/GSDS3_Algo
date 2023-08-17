#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100002];
int par[100002];
int vis[100002];
void dfs(int v){
    vis[v] = 1;
    for(auto nxt : adj[v]){
        if (vis[nxt]) continue;
        par[nxt] = v;
        vis[nxt] = 1;
        dfs(nxt);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = 1; 
            par[nxt] = cur;
            q.push(nxt);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i = 2; i <= n; i++){
        cout << par[i] << '\n';
    }    

}