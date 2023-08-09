#include <iostream>
#include <set>
#include <deque>
#define endl '\n'
using namespace std;

int N, M, V, x, y;
bool visited_dfs[1001];
bool visited_bfs[1001];
set<int> adj[1001];

void bfs(int num) {
    deque<int> q;
    q.push_back(num);
    int curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop_front();
        if (!visited_bfs[curr]) {
            cout << curr << " ";
            visited_bfs[curr] = true;
            for (auto it : adj[curr]) {
                if (!visited_bfs[it]) q.push_back(it);
            }
        } else {
            continue;
        }
    }
}

void dfs(int num) {
    if (!visited_dfs[num]) {
        cout << num << " ";
        visited_dfs[num] = true;
    }
    for (auto it: adj[num]) {
        if (!visited_dfs[it]) dfs(it);
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    cout.tie(0);
    cin >> N >> M >>V;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    dfs(V);
    cout << endl;
    bfs(V);
    return 0;
}
