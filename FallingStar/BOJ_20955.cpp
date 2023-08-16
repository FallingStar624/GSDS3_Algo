#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, u, v, cnt=0;
vector<int> adj[100001];
bool visited[100001];

void bfs(int start) {
    cnt++;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        visited[curr] = true;
        q.pop();
        for (auto it : adj[curr]) {
            if (visited[it]) continue;
            visited[it] = true;
            q.push(it);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        bfs(i);
    }

    cout << (cnt -1)+(M+cnt-1)-(N-1) << endl;
    return 0;
}

