#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

vector<int> adj[1001];
int vis[1001];
int main(){
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //BFS
    int num = 0;

    for(int i = 1; i <= v; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        num++;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto n: adj[cur]){
                if (vis[n]) continue;
                vis[n] = 1;
                q.push(n);
            }
        }
    }
    cout << num;
}