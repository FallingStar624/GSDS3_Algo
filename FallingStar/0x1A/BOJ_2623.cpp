#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M, total;
vector<int> adj[1001];
int indeg[1001];
vector<int> res;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> total;
        vector<int> tmp;
        for (int j=0; j<total; j++) {
            int num;
            cin >> num;
            tmp.push_back(num);
        }
        for (int j=0; j<tmp.size()-1; j++) {
            int u, v;
            u = tmp[j]; v = tmp[j+1];
            adj[u].push_back(v);
            indeg[v]++;
        }
    }
    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (indeg[i]==0) q.push(i);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (auto it : adj[curr]) {
            indeg[it]--;
            if (indeg[it]==0) q.push(it);
        }
    }

    if (res.size() != N) {
        cout << 0;
    } else {
        for (auto it : res) {
            cout << it << '\n';
        }
    }

    return 0;
}

