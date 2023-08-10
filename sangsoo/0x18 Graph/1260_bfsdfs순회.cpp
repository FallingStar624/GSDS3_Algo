#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> adj[1001];
int vis1[1001];
int vis2[1001];

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis1[v] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            if(vis1[nxt]) continue;
            q.push(nxt);
            vis1[nxt] = 1;
        }
    }
}

void dfs1(int v){
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis2[cur]) continue;
        vis2[cur] = 1;
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++){
            // 스택의 특성상 정점을 역순으로 넣어야함
            int nxt = adj[cur][adj[cur].size()-1-i];
            if(vis2[nxt]) continue;
            s.push(nxt);
        }
    }
}

void dfs2(int v){
    vis2[v] = 1;
    cout << v << ' ';
    for(auto nxt : adj[v]){
        if(vis2[nxt]) continue;
        dfs2(nxt);
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);        
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs2(v);
    cout << '\n';
    bfs(v);
}