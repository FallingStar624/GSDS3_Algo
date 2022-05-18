#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

int board[1002][1002];
bool visited[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m, n;

struct tp {
    int row, col;
    int time;
};

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<tp> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(board[i][j] == 1) {
                q.push({i, j, 1});
            }
        }
    }

    while(!q.empty()) {
        tp cur = q.front();
        q.pop();

        if(board[cur.row][cur.col] == 0 || board[cur.row][cur.col] == 1) {
            board[cur.row][cur.col] = cur.time;

            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.row + dx[dir];
                int ny = cur.col + dy[dir];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if(board[nx][ny] != 0)
                    continue;
                
                q.push({nx, ny, cur.time + 1});

            }
        }
    }

    int day = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }

            if(board[i][j] > 0) {
                day = max(day, board[i][j] - 1);
            }
        }
    }
    cout << day << '\n';

    return 0;
}