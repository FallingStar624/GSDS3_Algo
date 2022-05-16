#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M;
int board[102][102];
bool vis[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int result[102][102];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>N>>M;
    for (int i=0;i<N;i++)
    {
        string x;
        cin >>x;
        int m=0;
        for (int elem: x) {
            board[i][m++] = elem-48;            }
    }
    int num=1;
    queue<pair<int,int>> Q;
    vis[0][0]=1;
    Q.push({0,0});
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        num=result[cur.X][cur.Y];
        Q.pop();
        ++num;
        for (int dir=0;dir<4;dir++)
        {
            int nx=cur.X + dx[dir];
            int ny=cur.Y + dy[dir];
            if (nx<0||nx>=N||ny<0||ny>=M)continue;
            if (vis[nx][ny]||board[nx][ny]!=1)continue;
            vis[nx][ny]=1;
            result[nx][ny]=num;
            //cout<<nx<<", "<<ny<<"result : "<<num<<'\n';
            Q.push({nx,ny});
        }
    }
    cout<<result[N-1][M-1]+1;
}
