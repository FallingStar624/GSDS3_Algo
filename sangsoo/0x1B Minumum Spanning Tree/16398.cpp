#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> p(1005, -1);

int find(int x){
    if (p[x]<0) return x;
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

int v, e;
tuple<int, int, int> edge[1000005]; // {비용, 정점 1, 정점2}

int main(){
    cin >> v;
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            int cost;
            cin >> cost;
            if(i >= j) continue;
            edge[e++] = {cost, i, j};
        }
    }
    sort(edge, edge+e);
    int cnt = 0;
    long long ans = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
}