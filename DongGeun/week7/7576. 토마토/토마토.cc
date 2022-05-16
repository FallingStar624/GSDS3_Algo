#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M;
int board[1002][1002];
bool vis[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int result[1002][1002];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;

    queue<pair<int,int>> Q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                pair <int,int> temp= make_pair(i,j);
                vis[temp.X][temp.Y]=1;
                Q.push(temp);
                //cout<<"start "<<temp.X<<" "<<temp.Y<<'\n';
            }
        }
    }
    int num=1;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        num=result[cur.X][cur.Y];
        //cout<<"pop"<<'\n';
        Q.pop();
        ++num;
        for (int dir=0;dir<4;dir++)
        {
            int nx=cur.X + dx[dir];
            int ny=cur.Y + dy[dir];
            //cout<< nx<<" "<<ny<<"\n";
            if (nx<0||nx>=M||ny<0||ny>=N)continue;
            if (vis[nx][ny]||board[nx][ny]!=0)continue;
            vis[nx][ny]=1;
            result[nx][ny]=num;
            //cout<<nx<<", "<<ny<<" result : "<<num<<'\n';
            //cout<<"push"<<'\n';
            Q.push({nx,ny});
        }
    }
    int mx=0;
    bool flag=true;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, result[i][j]);
            if (result[i][j]==0&&board[i][j]==0)
            {
                //cout<<i<<j;
                flag=false;
            }
        }
    }
    if (flag)    cout<<mx;
    else cout<<"-1";
}