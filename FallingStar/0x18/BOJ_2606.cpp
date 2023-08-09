#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

int N, M, x, y, ans=-1;
bool visited[101];
set<int> adj[101];


void dfs(int num) {
    if (!visited[num]) {
        visited[num] = true;
        ans++;
    } else {
        return;
    }
    for (auto it: adj[num]) {
        if (!visited[it]) dfs(it);
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    dfs(1);
    cout << ans;
    return 0;
}
