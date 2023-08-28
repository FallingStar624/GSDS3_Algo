#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <functional>    // greater, less

using namespace std;

vector<int> p(1005,-1);

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

    int n;
    cin >> n;

    int cost;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> cost;
            if(i==j) continue;
            edges.push_back({cost, i, j});
        }
    }
    sort(edges.begin(), edges.end());

    int u, v;
    int cnt = 0;
    long long ans = 0;
    for(auto edge : edges) {
        tie(cost, u, v) = edge;
        if(!is_diff_group(u, v)) continue;
        ans += cost;
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << ans;

    return 0;
}