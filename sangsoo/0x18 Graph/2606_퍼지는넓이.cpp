// 본인 제외 퍼지는 넓이, 본인 포함하려면 cnt 초기화를 1로 하거나 마지막에 cnt+1을 리턴하면 된다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[101];
int vis[101];
int bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1; 
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = 1; 
            cnt++;
            q.push(nxt);
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
    cout << bfs(1);
}
