#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1005];
bool arr[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(arr[i]) 
            continue;;
        ans++;
        queue<int> q;
        q.push(i);
        arr[i] = true;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto node : adj[cur]) {
                if(arr[node]) continue;
                q.push(node);
                arr[node] = true;
            }
        }

    }
    cout << ans;
    return 0;
}