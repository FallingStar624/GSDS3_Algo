#include <iostream>
#include <vector>

using namespace std;

int v, e, a, b;
vector<int> adj[105];
int arr[105];
int ans = 0;

void dfs(int cur) {
    arr[cur] = 1;
    for(auto node : adj[cur]) {
        if(arr[node])
            continue;
        ans++;
        dfs(node);
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    while(e--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << ans;
    return 0;
}
 