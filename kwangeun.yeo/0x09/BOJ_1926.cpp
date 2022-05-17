#include <bits/stdc++.h>

using namespace std;

#define R first
#define C second
#define MAXR (505)
#define MAXC (505)

int paper[MAXR][MAXC];
bool vis[MAXR][MAXC];
queue<pair<int,int> > Q;
int paperR, paperC;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int BFS(int sr, int sc) {
    int area = 0;
    vis[sr][sc] = true;
    Q.push({sr, sc});
    area++;
    while (!Q.empty()) {
        pair<int, int> curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = curr.R + dr[i];
            int nc = curr.C + dc[i];
            if (nr < 0 || nr >= paperR || nc < 0 || nc >= paperC) continue;
            if (vis[nr][nc] || paper[nr][nc] == 0) continue;
            vis[nr][nc] = true;
            area++;
            Q.push({nr, nc});
        }
    }
    return area;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> paperR >> paperC;
    for (int r = 0; r < paperR; ++r) {
        for (int c = 0; c < paperC; ++c) {
            cin >> paper[r][c];
        }
    }

    int max_area = 0;
    int cnt = 0;
    for (int r = 0; r < paperR; ++r) {
        for (int c = 0; c < paperC; ++c) {
            if (paper[r][c] == 0 || vis[r][c]) continue;
            int area = BFS(r, c);
            max_area = max(area, max_area);
            cnt++;
        }
    }
    cout << cnt << '\n' << max_area << '\n';

    return 0;
}