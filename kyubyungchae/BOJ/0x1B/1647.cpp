#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>    // greater, less

using namespace std;

vector<int> p(100002,-1);

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

vector< tuple<int,int,int> > edges;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int u, v, cost;
    while(m--) {        
        cin >> u >> v >> cost;
        edges.push_back({cost, u, v});
    }
    sort(edges.begin(), edges.end());

    int cnt = 0, ans = 0, mc = 0;
    for(auto edge : edges) {
        tie(cost, u, v) = edge;
        if(!is_diff_group(u, v)) continue;
        ans += cost;
        mc = max(mc, cost);
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << ans - mc;

    return 0;
}