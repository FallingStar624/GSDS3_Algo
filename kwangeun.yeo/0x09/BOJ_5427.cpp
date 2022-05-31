#include <iostream>
#include <queue>
using namespace std;
#define row first
#define col second
#define MAXN (1004)

int T, R, C;
char building[MAXN][MAXN];
int dist_f[MAXN][MAXN];
int dist_s[MAXN][MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

queue<pair<int, int> > Q_f;
queue<pair<int, int> > Q_s;

void BFS_F() {
    while (!Q_f.empty()) {
        auto curr = Q_f.front(); Q_f.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (dist_f[nr][nc] >= 0) continue;
            if (building[nr][nc] == '#') continue;
            Q_f.push({nr, nc});
            dist_f[nr][nc] = dist_f[curr.row][curr.col] + 1;
        }
    }
}

int BFS_S() {
    while (!Q_s.empty()) {
        auto curr = Q_s.front(); Q_s.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) {
                return dist_s[curr.row][curr.col] + 1;
            }
            if (dist_s[nr][nc] >= 0) continue;
            if (building[nr][nc] == '#') continue;
            if (dist_f[nr][nc] >= 0 && dist_f[nr][nc] <= dist_s[curr.row][curr.col] + 1) continue;
            Q_s.push({nr, nc});
            dist_s[nr][nc] = dist_s[curr.row][curr.col] + 1;
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cin >> C >> R;
        for (int r = 0; r < R; ++r) {
            fill(dist_f[r], dist_f[r] + C, -1);
            fill(dist_s[r], dist_s[r] + C, -1);
            cin >> building[r];
            for (int c = 0; c < C; ++c) {
                if (building[r][c] == '@') {
                    dist_s[r][c] = 0;
                    Q_s.push({r, c});
                } else if (building[r][c] == '*') {
                    dist_f[r][c] = 0;
                    Q_f.push({r, c});
                }
            }
        }

        BFS_F();
        int ans = BFS_S();
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';

        while (!Q_f.empty())
            Q_f.pop();
        while (!Q_s.empty())
            Q_s.pop();
    }

    return 0;
}