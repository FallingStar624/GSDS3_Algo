#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M;
bool vis[303][303];
int board[303][303];

int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

int result[303][303];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N ;
    int start_x,start_y,num,end_x,end_y;
    while(N--)
    {
        cin>>M;
        for (int i=0;i<303;i++)
        {
            for (int j=0;j<303;j++)
            {
                //board[i][j]=0;
                vis[i][j]=0;
                result[i][j]=0;
            }
        }
        cin >>start_x>>start_y;
        cin >>end_x>>end_y;
        queue<pair<int,int>> Q;
        vis[start_x][start_y]=1;
        board[start_x][start_y]=1;
        board[end_x][end_y]=1;
        Q.push({start_x,start_y});
        while(!Q.empty()) {
            pair<int, int> cur = Q.front();
            num = result[cur.X][cur.Y];
            Q.pop();
            ++num;
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= M || ny < 0 || ny >= M)
                {
                    continue;
                }

                if (vis[nx][ny]!=0){
                    //cout<<vis[nx][ny]<<" 2: \n";
                    continue;
                }
                vis[nx][ny] = 1;
                result[nx][ny] = num;
                //cout<<nx<<", "<<ny<<"result : "<<num<<'\n';
                Q.push({nx, ny});
            }
        }
        cout<<result[end_x][end_y]<<'\n';
    }
}