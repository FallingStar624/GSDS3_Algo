#include <iostream>
#include <queue>
using namespace std;
#define row first
#define col second
#define MAXN (102)

int N;
char draw_rgb[MAXN][MAXN];
char draw_rb[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pair<int, int> > Q;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

void BFS(int sr, int sc, char color, bool rg_tell) {
    vis[sr][sc] = true;
    Q.push({sr, sc});
    while (!Q.empty()) {
        pair<int, int> curr = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (vis[nr][nc] == true) continue;
            if ((rg_tell == true && draw_rgb[nr][nc] != color) || \
                (rg_tell == false && draw_rb[nr][nc] != color)) continue;
            Q.push({nr, nc});
            vis[nr][nc] = true;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> draw_rgb[r];
        for (int c = 0; c < N; ++c) {
            if (draw_rgb[r][c] == 'G') draw_rb[r][c] = 'R';
            else draw_rb[r][c] = draw_rgb[r][c];
        }
    }

    int ans = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (vis[r][c] == false) {
                BFS(r, c, draw_rgb[r][c], true);
                ans++;
            }
        }
    }
    cout << ans << ' ';
    ans = 0;
    for (int r = 0; r < N; ++r) {
        fill(vis[r], vis[r] + N, false);
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (vis[r][c] == false) {
                BFS(r, c, draw_rb[r][c], false);
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}