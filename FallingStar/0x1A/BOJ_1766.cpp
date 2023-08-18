#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<int> adj[32001];
int deg[32001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i=1; i<=N; i++) {
        if (deg[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.top();
        q.pop();
        cout << curr << ' ';
        for (auto i : adj[curr]) {
            deg[i]--;
            if (deg[i]==0) q.push(i);
        }
    }
    return 0;
}
