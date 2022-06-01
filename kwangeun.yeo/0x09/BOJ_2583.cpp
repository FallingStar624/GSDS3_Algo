#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define row first
#define col second
#define MAXN (104)

int R, C, K;
bool vis[MAXN][MAXN];
int paper[MAXN][MAXN];
int area[MAXN * MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

queue<pair<int, int> > Q;

int BFS(int sr, int sc) {
    Q.push({sr, sc});
    vis[sr][sc] = true;
    int area = 1;

    while (!Q.empty()) {
        auto curr = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (paper[nr][nc] == 1 || vis[nr][nc] == true) continue;
            Q.push({nr, nc});
            vis[nr][nc] = true;
            area++;
        }
    }
    return area;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C >> K;
    for (int i = 0; i < K; ++i) {
        int ldr, ldc, rur, ruc;
        cin >> ldc >> ldr >> ruc >> rur;
        for (int r = ldr; r < rur; ++r) {
            for (int c = ldc; c < ruc; ++c) {
                paper[r][c] = 1;
            }
        }
    }

    int area_cnt = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (vis[r][c] == false && paper[r][c] == 0) {
                area[area_cnt++] = BFS(r, c);
            }
        }
    }
    cout << area_cnt << '\n';
    sort(area, area + area_cnt);
    for (int i = 0; i < area_cnt; ++i) {
        cout << area[i] << ' ';
    }
    cout << '\n';

    return 0;
}