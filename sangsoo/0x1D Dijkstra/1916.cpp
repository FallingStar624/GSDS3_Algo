#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define X first
#define Y second

using namespace std;

const int INF = 0x3f3f3f3f;
vector <pair<int, int>> adj[1005];
int d[1005];
int n, m, st, en;

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i ++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    cin >> st >> en;
    fill(d, d+n+1, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+ nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    cout << d[en];
}