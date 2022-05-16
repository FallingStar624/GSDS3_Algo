#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K,N,M;
char board[1002][1002];
int fire[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int result[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    cin>>K;
    while (K--)
    {

        cin >> M>> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                fire[i][j]=-1;
                result[i][j]=-1;
            }
        }
        int human_x,human_y;
        queue<pair<int, int>> Q;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            int m = 0;
            for (auto ch: s) {
                if (ch == '*') {
                    fire[i][m] = 0;
                    Q.push({i, m});
                }
                else if (ch == '@') {
                    human_x = i;
                    human_y = m;
                    result[i][m] = 0;
                }
                board[i][m++] = ch;
            }
        }
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
                if (fire[nx][ny]>=0 || board[nx][ny] == '#')continue;
                fire[nx][ny]=fire[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }
        Q.push({human_x, human_y});
        bool flag=false;
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                {
                    cout<<result[cur.X][cur.Y]+1<<'\n';
                    flag=true;
                    break;
                }
                if (result[nx][ny]>=0 || board[nx][ny] == '#')continue;
                if (fire[nx][ny]!=-1&&result[cur.X][cur.Y]+1>=fire[nx][ny])continue;
                result[nx][ny]=result[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
            if (flag) break;
        }
        if (!flag)
        {
            cout<<"IMPOSSIBLE\n";
        }
    }

}