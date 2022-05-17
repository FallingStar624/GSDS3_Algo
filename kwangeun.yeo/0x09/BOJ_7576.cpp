#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
#define MAXR (1004)
#define MAXC (1004)

int R, C;
queue<pair<int,int> > Q;
int box[MAXR][MAXC];
int dist[MAXR][MAXC];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main () {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> C >> R;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> box[r][c];
            if (box[r][c] == 1) {
                Q.push({r, c});
                dist[r][c] = 0;
            } else {
                dist[r][c] = -1;
            }
        }
    }
    while (!Q.empty()) {
        pair<int, int> curr = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (box[nr][nc] != 0 || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[curr.row][curr.col] + 1;
            Q.push({nr, nc});
        }
    }

    int answer = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (box[r][c] != -1 && dist[r][c] == -1) { answer = -1; break; }
            answer = max(answer, dist[r][c]);
        }
        if (answer == -1) break;
    }
    cout << answer << '\n';

    return 0;
}
