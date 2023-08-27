#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(1005, -1);
vector<int> p2(1005, -1);

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


int find2(int x){
    if(p2[x] < 0) return x;
    return p2[x] = find2(p2[x]);
}

bool is_diff_group2(int u, int v){
    u = find2(u); v = find2(v);
    cout << "u : " << u << " v : " << v << endl;
    if(u == v) return 0;
    if(p2[u] == p2[v]) p2[u]--;
    if(p2[u] < p2[v]) p2[v] = u;
    else p2[u] = v;
    return 1;
}

int v, e;
tuple <int, int, int> edge[1000005];
tuple <int, int, int> edge2[1000005];

int descending(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<0>(a) > get<0>(b);
}
int main(){
    cin >> v >> e;
    e = e+1;
    v = v+1;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
        edge2[i] = {cost, a, b};
    }
    sort(edge, edge+e);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        cout << "a : " << a << " b : " << b << " cost : " << cost <<  endl;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    int mn = ans;

    sort(edge2, edge2+e, descending);
    int cnt2 = 0;
    int ans2 = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge2[i];
        cout << "2 a : " << a << " b : " << b << " cost : " << cost <<  endl;
        if(!is_diff_group2(a, b)) continue;
        cout << "3 a : " << a << " b : " << b << " cost : " << cost <<  endl;
        ans2 += cost;
        cnt2++;
        if(cnt2 == v-1) break;
    }
    int mx = ans2;
    cout <<"mx : " << mx << " mn : " << mn << endl;
    cout << mx*mx - mn*mn;
}