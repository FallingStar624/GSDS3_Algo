#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
vector<int> adj[100002];
int parent[100002];

void dft(int num) {
    for (auto it : adj[num]) {
        if (parent[num] == it) continue;
        parent[it] = num;
        dft(it);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dft(1);
    for (int i=2; i<=n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}
