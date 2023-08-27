/*
MST로 연결하고 가장 큰 에지를 빼주면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> p(100005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

/*
is_diff_group
 - 같은 그룹이면 : return 0
 - 다른 그룹이면 : 같은 그룹으로 바꿔준다.
   - 이때 rank가 같으면 rank를 증가시키고(여기서는 negative방향으로 증가), 
   - rank의 절대값이 더 작은 쪽을 더 큰 쪽에 붙여주면 높이가 최소화 된다.(Union by rank)
*/

bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
tuple <int, int, int> edge[1000005]; // {비용, 정점1, 정점2}

int main(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge+e);
    int cnt = 0;
    int ans = 0;
    int mxcost = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        mxcost = cost;
        if(cnt == v-1) break;
    }
    cout << ans - mxcost;
}