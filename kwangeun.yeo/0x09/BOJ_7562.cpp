#include <iostream>
#include <queue>
using namespace std;
#define row first
#define col second
#define MAXN (303)
int T, N;
int vis[MAXN][MAXN];
int dr[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
queue<pair<int, int> > Q;

int BFS(int sr, int sc, int tr, int tc) {
    vis[sr][sc] = 0;
    Q.push({sr, sc});

    while (!Q.empty()) {
        pair<int, int> curr = Q.front(); Q.pop();
//        if (curr.row == tr && curr.col == tc) return vis[curr.row][curr.col];
        for (int i = 0; i < 8; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (vis[nr][nc] == -1) {
                Q.push({nr, nc});
                vis[nr][nc] = vis[curr.row][curr.col] + 1;
            }
        }
    }
    return vis[tr][tc];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for (int tn = 0; tn < T; ++tn) {
        cin >> N;
        for (int r = 0; r < N; ++r) {
            fill(vis[r], vis[r] + N, -1);
        }
        int sr, sc, tr, tc;
        cin >> sr >> sc >> tr >> tc;
        cout << BFS(sr, sc, tr, tc) << '\n';
    }
    return 0;
}