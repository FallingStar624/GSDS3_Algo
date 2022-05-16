#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N;
int board[52][52];
bool vis[52][52];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N ;
    int width, height,loc,loc_x,loc_y;
    while(N--)
    {
        cin >>height>>width>>loc;
        for (int i=0;i<52;i++)
            for (int j=0;j<52;j++)
            {
                board[i][j]=0;
                vis[i][j] = 0;
            }
        while(loc--)
        {
            cin>>loc_x>>loc_y;
            board[loc_x][loc_y]=1;
        }
        queue<pair<int,int>> Q;
        int num=0;
        for (int i=0;i<height;i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (board[i][j] == 0 || vis[i][j])
                {
                    continue;
                }
                num++;
                vis[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    //cout<<"pop "<<cur.X<<cur.Y<<"\n";
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= height || ny < 0 || ny >= width) { continue; }
                        if (vis[nx][ny]||board[nx][ny]!=1)continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << num << '\n';
    }
}