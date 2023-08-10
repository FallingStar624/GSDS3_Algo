#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[52];
int vis[52][52];
int score[52];
int lv[52][52]; // score이자 level이자 거리
vector<int> result;

int bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v][v] = 1; 
    lv[v][v] = 0; // level(거리)
    int mx = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(vis[v][nxt]) continue;
            vis[v][nxt] = 1;
            lv[v][nxt] = lv[v][cur]+1;
            if(lv[v][nxt] > mx) mx = lv[v][nxt];
            q.push(nxt);
        }
    }
    return mx;
}

int main(){
    int n;
    cin >> n;
    while(1){
        int a, b;
        cin >> a >> b;
        if((a == -1) && (b == -1)) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mn = 53; int cnt = 0;
    for(int i = 1; i <= n; i++){
        score[i] = bfs(i);
        if(score[i] < mn) mn = score[i];
    }
    for(int i = 1; i <= n ; i++){
        if(score[i]==mn){
            cnt++;
            result.push_back(i);
        }
    }
    cout << mn << " "<< cnt << '\n';
    sort(result.begin(), result.end());
    for(auto i : result)
        cout << i << " ";
}