#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[52][52];
int vis[52][52];
int T;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        int M, N, K;
        cin >> M >> N >> K;
        for(int i = 0; i < M; i++){   // initialization 이부분이 없으면 틀림
            for(int j = 0; j < N; j++){
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 0 || vis[i][j]) continue; // 배추가 아니거나 방문했으면 continue
                cnt++;
                queue<pair<int, int>> q; // 배추면 q를 만듦
                q.push({i, j}); vis[i][j] = 1;
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx > M  || ny < 0 || ny > N) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}