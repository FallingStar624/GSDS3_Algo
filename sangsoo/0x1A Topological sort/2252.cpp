#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int indegree[32002];
vector<int> adj[32002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i); 
    }
    vector<int> result;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(auto nxt: adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }    
    }
    for(auto e : result) cout << e << ' ';
}