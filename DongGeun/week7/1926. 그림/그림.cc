#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M;
int board[502][502];
bool vis[502][502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>N>>M;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)        {   cin>>board[i][j];       }
    int mx=0;
    int num=0;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
        {
            if (board[i][j]==0||vis[i][j]) continue;
            num++;
            queue<pair<int,int>> Q;
            vis[i][j]=1;
            Q.push({i,j});
            int area=0;
            while(!Q.empty())
            {
                area++;
                pair<int,int> cur = Q.front();
                Q.pop();
                for (int dir=0;dir<4;dir++)
                {
                    int nx=cur.X + dx[dir];
                    int ny=cur.Y + dy[dir];
                    if (nx<0||nx>=N||ny<0||ny>=M)continue;
                    if (vis[nx][ny]||board[nx][ny]!=1)continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
            mx=max(mx,area);
        }
    cout<<num<<'\n'<<mx;
}
