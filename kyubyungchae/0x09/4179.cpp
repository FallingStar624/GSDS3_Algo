#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < n; i++) {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
        
    queue<pair<int,int>> qj;
    queue<pair<int,int>> qf;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(board[i][j] == 'F') {
                qf.push({i, j});
                dist1[i][j] = 0;
            }

            if(board[i][j] == 'J') {
                qj.push({i, j});
                dist2[i][j] = 0;
            }

        }
    }

    while(!qf.empty()) {
        auto cur = qf.front();
        qf.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            qf.push({nx, ny});
        }
    }

    while(!qj.empty()) {
        auto cur = qj.front();
        qj.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') 
                continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            qj.push({nx, ny});
        }

    }
    cout << "IMPOSSIBLE";

    return 0;
}

