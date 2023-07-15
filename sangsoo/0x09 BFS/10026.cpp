#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board1[102][102]; // 일반인
int vis1[102][102];
char board2[102][102]; // 적록색약
int vis2[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char tmp;
            cin >> tmp;
            board1[i][j] = tmp;
            board2[i][j] = tmp;
        }
    }
    // 일반인
    int cnt1 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis1[i][j]) continue;
            cnt1++;
            queue<pair<int, int>> q;
            char c = board1[i][j];
            q.push({i, j});
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0||nx >= N || ny < 0||ny >= N) continue; // 범위 밖이면 넘어감
                    if (vis1[nx][ny] || board1[nx][ny] != c) continue; // 이미 방문했거나 같은 색깔 아닌경우
                    vis1[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    // 적록색약
    int cnt2 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis2[i][j]) continue;
            cnt2++;
            queue<pair<int, int>> q;
            char c = board2[i][j];
            q.push({i, j});
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0||nx >= N || ny < 0||ny >= N) continue; // 범위 밖이면 넘어감
                    if (vis2[nx][ny]) continue;
                    if (c == "R"[0] && board2[nx][ny] == "B"[0]) continue;
                    if (c == "G"[0] && board2[nx][ny] == "B"[0]) continue;
                    if (c == "B"[0] && board2[nx][ny] != "B"[0]) continue;
                    vis2[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt1 << " " << cnt2;
}