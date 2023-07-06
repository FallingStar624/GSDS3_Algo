#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int jtime[1002][1002]; int jvis[1002][1002];
int ftime[1002][1002]; int fvis[1002][1002];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;
    // fire
    // initialize 
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(board[i][j] == 'F'){
                fq.push({i,j}); // x, y, time
                ftime[i][j] = 0;
                fvis[i][j] = 1;
            }
            else {
                ftime[i][j] = -1; 
                fvis[i][j] = 0;
            }
        }
    }

    while(!fq.empty()){
        pair<int,int> cur = fq.front(); fq.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (fvis[nx][ny]||board[nx][ny]=='#') continue;
            fvis[nx][ny] = 1;
            ftime[nx][ny] = ftime[cur.X][cur.Y]+1;
            fq.push({nx, ny});

        }
    }

    // J
    // initialize
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(board[i][j] == 'J'){
                jq.push({i,j}); // x, y
                jtime[i][j] = 0;
                jvis[i][j] = 1;
            }
            else {
                jtime[i][j] = -1;
                jvis[i][j] = 0;
            }

        }
    }

    while(!jq.empty()){
        pair<int, int> cur = jq.front(); jq.pop();
        if(cur.X == 0 || cur.X == n-1 || cur.Y == 0 || cur.Y == m-1){
            cout << jtime[cur.X][cur.Y]+1;
            return 0;
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (jvis[nx][ny]||board[nx][ny]=='#') continue;
            if (ftime[nx][ny] != -1 && jtime[cur.X][cur.Y]+1 >= ftime[nx][ny]) continue;
            // 불이 번졌는데, J가 늦게 갔으면 continue
            // 불이 아예 안번졌으면... J는 계속 진행..
            jvis[nx][ny] = 1;
            jtime[nx][ny] = jtime[cur.X][cur.Y]+1;

            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}