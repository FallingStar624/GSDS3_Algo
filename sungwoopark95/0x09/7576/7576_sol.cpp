#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    queue<array<int, 3>> Q;

    int N, M; // N: row, M: column
    cin >> M >> N;
    int box[N][M];
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) { Q.push({i, j, box[i][j]}); }
        }
    }

    // BFS
    while (!Q.empty()) {
        array<int, 3> curr = Q.front();
        Q.pop();

        if (box[curr[0]][curr[1]] < 0 || box[curr[0]][curr[1]] > 1) { continue; } // -1이거나 1보다 크면 pass
        box[curr[0]][curr[1]] = curr[2];
        for (int dir=0;dir<4;dir++) {
            int nx = curr[0] + dx[dir];
            int ny = curr[1] + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
            if (box[nx][ny] != 0) { continue; }
            Q.push({nx, ny, curr[2]+1});
        }
    }

    // time
    int time = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (box[i][j] == 0) { 
                cout << -1 << "\n";
                return 0; 
            }
            else if (box[i][j] > 0) {
                time = max(time, box[i][j]);
            }
        }
    }

    cout << time-1 << "\n";
    return 0;
}