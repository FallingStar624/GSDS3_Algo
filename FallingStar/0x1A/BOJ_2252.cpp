#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> adj[32001];
int indeg[32001];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (indeg[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for (auto it : adj[curr]) {
            indeg[it]--;
            if (indeg[it]==0) q.push(it);
        }
    }

    return 0;
}
