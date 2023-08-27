#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
bool is_diff_group(int u, int v){
    ;
}
int main(){
    int v, e;
    // {비용, 정점 1, 정점2}
    tuple<int, int, int> edge [100005];

    sort(edge, edge+e);
    int cnt = 0;
    for(int i = 0; i < e; i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        cout << cost << ' ' << a << b;
        cnt++;
        if(cnt == v-1) break;
    }
}