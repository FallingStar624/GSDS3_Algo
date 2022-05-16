#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M;
char board[1002][1002];
bool vis[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int result[1002][1002];
int yes,no;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int m = 0;
        for (auto ch: s) {
            board[i][m++] = ch;
        }
    }
    int num = 0;
    char cur_ch;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            num++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                cur_ch = board[cur.X][cur.Y];
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
                    if (vis[nx][ny] || board[nx][ny] != cur_ch)continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    yes = num;
    num = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            num++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                cur_ch= board[cur.X][cur.Y];
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
                    if (vis[nx][ny])continue;
                    if (cur_ch=='B')
                    {
                        if (board[nx][ny]!= cur_ch)continue;
                    }
                    else
                    {
                        if (board[nx][ny]== 'B')continue;
                    }
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    no=num;
    cout<<yes<<' '<<no;
}