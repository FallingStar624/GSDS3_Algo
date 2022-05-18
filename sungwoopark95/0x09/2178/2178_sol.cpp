#include <bits/stdc++.h>
using namespace std;

string maze[100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int dist[N][M];

    for (int i=0;i<N;i++) {
        cin >> maze[i];
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            dist[i][j] = -1;
        }
    }

    // 탐색 시작
    queue<pair<int, int> > Q;
    dist[0][0] = 0; // vistied 역할
    Q.push({0, 0});
    while (!Q.empty()) {
        pair<int, int> curr = Q.front();
        Q.pop();
        for (int k=0;k<4;k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
            if (dist[nx][ny] >= 0 || maze[nx][ny] != '1') { continue; }
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[N-1][M-1]+1 << "\n";
    return 0;
}