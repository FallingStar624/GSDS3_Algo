#include <bits/stdc++.h>

using namespace std;

#define row first
#define col second
#define MAXR 1004
#define MAXC 1004

queue<pair<int, int> > FQ;
queue<pair<int, int> > JQ;
int distF[MAXR][MAXC];
int distJ[MAXR][MAXC];
char maze[MAXR][MAXC];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int R, C;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        cin >> maze[r];
        fill(distF[r], distF[r] + C, -1);
        fill(distJ[r], distJ[r] + C, -1);
        for (int c = 0; c < C; ++c) {
            if (maze[r][c] == 'F') {
                distF[r][c] = 0;
                FQ.push({r, c});
            }
            else if (maze[r][c] == 'J') {
                distJ[r][c] = 0;
                JQ.push({r, c});
            }
        }
    }

    while (!FQ.empty()) {
        pair<int, int> curr = FQ.front(); FQ.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (distF[nr][nc] >= 0 || maze[nr][nc] == '#') continue;
            distF[nr][nc] = distF[curr.row][curr.col] + 1;
            FQ.push({nr, nc});
        }
    }
    while (!JQ.empty()) {
        pair<int, int> curr = JQ.front(); JQ.pop();
        for (int i = 0; i < 4; i++) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                cout << distJ[curr.row][curr.col] + 1;
                return 0;
            }
            if (distJ[nr][nc] >= 0 || maze[nr][nc] == '#') continue;
            if (distF[nr][nc] != -1 && distF[nr][nc] <= distJ[curr.row][curr.col] + 1) continue;
            distJ[nr][nc] = distJ[curr.row][curr.col] + 1;
            JQ.push({nr, nc});
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}