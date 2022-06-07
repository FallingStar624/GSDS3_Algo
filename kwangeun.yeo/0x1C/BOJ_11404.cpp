#include <iostream>
#define INF (0x3f3f3f3f)
#define MAXV (103)

using namespace std;
int V, E;
int d[MAXV][MAXV];

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            d[i][j] = i == j ? 0 : INF;
        }
    }
    for (int i = 0; i < E; ++i) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        d[src][dst] = min(d[src][dst], cost);
    }
    for (int mid = 1; mid <= V; ++mid) {
        for (int start = 1; start <= V; ++start) {
            for (int end = 1; end <= V; ++end) {
                d[start][end] = min(d[start][end], d[start][mid] + d[mid][end]);
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}