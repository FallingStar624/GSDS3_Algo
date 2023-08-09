#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

int N, M, x, y, ans=0;
bool visited[1001] {false};
set<int> adj[1001];

void bfs(int num) {
    if (visited[num]) return;
    visited[num] = true;
    for (auto it: adj[num]) {
        if (!visited[it]) bfs(it);
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
    for (int i=1; i<N+1; i++) {
        if (not visited[i]) {
            ans++;
            bfs(i);
        } else {
            continue;
        }
    }
    cout << ans;
    return 0;
}
