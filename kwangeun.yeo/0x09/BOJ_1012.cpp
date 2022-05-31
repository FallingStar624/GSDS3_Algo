#include <iostream>
#include <queue>
using namespace std;
#define row first
#define col second
#define MAXR (50)
#define MAXC (50)

int T, R, C, K;
queue<pair<int, int> > Q;
int farm[MAXR][MAXC];
bool vis[MAXR][MAXC];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

void bfs(int sr, int sc) {
    vis[sr][sc] = true;
    Q.push({sr, sc});
    while (!Q.empty()) {
        pair<int, int> curr = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (farm[nr][nc] == 0 || vis[nr][nc] == true) continue;
            vis[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cin >> C >> R >> K;
        for (int j = 0; j < R; ++j) {
            fill(vis[j], vis[j] + C, false);
            fill(farm[j], farm[j] + C, 0);
        }
        for (int i = 0; i < K; ++i) {
            int r, c;
            cin >> c >> r;
            farm[r][c] = 1;
        }
        int ans = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (farm[r][c] == 1 && vis[r][c] == false) {
                    ans++;
                    bfs(r, c);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}