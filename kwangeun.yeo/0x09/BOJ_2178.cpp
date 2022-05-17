#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
#define MAXR (104)
#define MAXC (104)

queue<pair<int,int> > Q;
int dist[MAXR][MAXC];
char maze[MAXR][MAXC];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int R, C;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> R >> C;
    for (int r = 0; r < R; ++r)
        cin >> maze[r];

    Q.push({0, 0});
    dist[0][0] = 1;
    while (!Q.empty()) {
        pair<int,int> curr = Q.front(); Q.pop();
        if (curr.row == R - 1 && curr.col == C - 1) {
            cout << dist[curr.row][curr.col];
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (maze[nr][nc] == '0' || dist[nr][nc] > 0) continue;
            Q.push({nr, nc});
            dist[nr][nc] = dist[curr.row][curr.col] + 1;
        }
    }

    return 0;
}