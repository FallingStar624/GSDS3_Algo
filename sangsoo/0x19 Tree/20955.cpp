#include <iostream>
#include <queue>
using namespace std;
int n, m;
vector<int> adj[100002];
int vis[100002];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if (vis[i]) continue;
        queue<int> q;
        cnt++;
        vis[i] = 1;
        q.push(i);
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    int remove = m + cnt - 1 - (n - 1); // 원래 에지 + 추가된 에지 (섬개수 -1) - 최종 개수(n-1)
    cout << cnt-1 + remove;
}
