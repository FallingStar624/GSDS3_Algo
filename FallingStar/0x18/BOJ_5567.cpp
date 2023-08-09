#include <iostream>
#include <set>
#include <deque>
#define endl '\n'
using namespace std;

int N, M, x, y, ans=-1;
bool visited[501];
set<int> adj[501];

void bfs(int num, int depth) {
    deque<pair<int, int>> q;
    q.emplace_back(pair(num, depth));
    pair<int, int> curr;
    while (!q.empty()) {
        curr = q.front();
        int f = curr.first;
        int s = curr.second;
        q.pop_front();
        if (!visited[f]) {
            visited[f] = true;
            ans++;
            for (auto it : adj[f]) {
                if (!visited[it] and s+1<3) {
                    q.emplace_back(pair(it, s+1));
                }
            }
        } else {
            continue;
        }
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
    bfs(1, 0);
    cout << ans;
    return 0;
}
