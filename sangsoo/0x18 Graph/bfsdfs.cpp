#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector<int> adj[10];
int vis[10];
// BFS 연결 그래프에서 순회, 시작 노드 v
void bfs_traverse(int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }
}

// BFS 연결 그래프에서 V번과 정점과의 거리
vector<int> adj[10];
int dist[10];
void bfs_dist(int v){
    fill(dist, dist+10, -1);
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur]+1;
        }
    }
}

// BFS 연결그래프가 아닐 때 순회
vector<int> adj[10];
bool vis[10];
int v = 9; // 정점의 수
void bfs_traverse2(){
    queue<int> q;
    for(int i = 1; i <= v; i++){
        if(vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            cout << cur << ' ';
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = 1;
            }
        }
    }
}

// DFS 연결그래프에서 순회, 비재귀 ver1 시작노드 v;
vector<int> adj[10];
int vis[10];
void dfs(){
    stack<int> s;
    s.push(v);
    vis[v] = 1;
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = 1;
        }
    }
}

// DFS 연결그래프에서 순회, 비재귀 ver2 (재귀와 같게 출력), 시작노드 v
vector<int> adj[10];
int vis[10];
void dfs(int v){
    stack<int> s;
    s.push(v);
    // vis[1] = 1; 삭제
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis[cur]) continue;
        vis[cur] = 1; // 추가
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++){
            // 스택의 특성상 정점을 역순으로 넣어야함
            int nxt = adj[cur][adj[cur].size()-1-i];
            if(vis[nxt]) continue;
            s.push(nxt);
            // vis[nxt] = 1; 삭제
        }
    }
}


// DFS 연결 그래프에서 순회, 재귀

vector<int> adj[10];
int vis[10];
void dfs(int cur){
    vis[cur] = 1;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }

}