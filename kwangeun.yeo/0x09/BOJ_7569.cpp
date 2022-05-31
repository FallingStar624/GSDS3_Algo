#include <iostream>
#include <queue>
using namespace std;
#define MAXN (104)

typedef struct {
    int h, r, c;
} TOMATO;

queue<TOMATO> Q;
int C, R, H;
int box[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int dr[6] = {0, 0, -1, 0, 1, 0};
int dc[6] = {0, 0, 0, -1, 0, 1};
int dh[6] = {-1, 1, 0, 0, 0, 0};

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> C >> R >> H;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < R; ++r) {
            fill(vis[h][r], vis[h][r] + C, -1);
            for (int c = 0; c < C; ++c) {
                cin >> box[h][r][c];
                if (box[h][r][c] == 1) {
                    Q.push(TOMATO{h, r, c});
                    vis[h][r][c] = 0;
                }
            }
        }
    }
    while (!Q.empty()) {
        TOMATO curr = Q.front(); Q.pop();
        for (int i = 0; i < 6; ++i) {
            int nh = curr.h + dh[i];
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= R || nc >= C) continue;
            if (vis[nh][nr][nc] == -1 && box[nh][nr][nc] == 0) {
                Q.push(TOMATO{nh, nr, nc});
                vis[nh][nr][nc] = vis[curr.h][curr.r][curr.c] + 1;
            }
        }
    }

    int ans = -1;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (box[h][r][c] == 0 && vis[h][r][c] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(vis[h][r][c], ans);
            }
        }
    }
    cout << ans;

    return 0;
}