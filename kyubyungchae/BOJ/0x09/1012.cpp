#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int board[51][51];
bool visited[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;

queue<pair<int,int>> q;

void bfs(int x, int y) {
  visited[x][y] = true;
  q.push({ x,y });
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny] || board[nx][ny] != 1) continue;
      visited[nx][ny] = true;
      q.push({ nx,ny });
    }
  }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> m >> n >> k;
        int x, y;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    result++;
                }
            }
        }
        cout << result << "\n";

        // reset
        for(int i = 0; i < n; i++) {
            fill(board[i], board[i]+m, 0);
            fill(visited[i], visited[i]+m, false);
        }

    }

    return 0;
}

