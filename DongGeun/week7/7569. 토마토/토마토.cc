#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M,K;
int board[102][102][102];
bool vis[102][102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dz[2]={1,-1};

int result[102][102][102];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N >> M>>K;
    queue<tuple<int,int,int>> Q;
    for (int k = 0; k < K; k++)
    {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    tuple< int,int,int> temp = make_tuple(i, j,k);
                    vis[i][j][k] = 1;
                    Q.push(temp);
                    //cout<<"start "<<temp.X<<" "<<temp.Y<<'\n';
                }
            }
        }
    }
    int num;
    while(!Q.empty())
    {
        tuple<int,int,int> cur = Q.front();
        int cur_x=get<0>(cur);
        int cur_y=get<1>(cur);
        int cur_z=get<2>(cur);
        num=result[cur_x][cur_y][cur_z];
        //cout<<"pop"<<'\n';
        Q.pop();
        ++num;
        for (int dir=0;dir<4;dir++)
        {
            int nx=cur_x + dx[dir];
            int ny=cur_y + dy[dir];
            //cout<< nx<<" "<<ny<<"\n";
            if (nx<0||nx>=M||ny<0||ny>=N)continue;
            if (vis[nx][ny][cur_z]||board[nx][ny][cur_z]!=0)continue;
            vis[nx][ny][cur_z]=1;
            result[nx][ny][cur_z]=num;
            //cout<<nx<<", "<<ny<<", "<<cur_z<<" result : "<<num<<'\n';
            Q.push({nx,ny,cur_z});
        }
        for (int dir=0;dir<2;dir++)
        {
            int nz=cur_z + dz[dir];
            if (nz<0||nz>=K)
            {
                continue;
            }
            if (vis[cur_x][cur_y][nz]||board[cur_x][cur_y][nz]!=0)
            {
                continue;
            }
            vis[cur_x][cur_y][nz]=1;
            result[cur_x][cur_y][nz]=num;
            Q.push({cur_x,cur_y,nz});
        }
    }
    int mx=0;
    bool flag=true;
    for (int k = 0; k < K; k++)
    {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mx = max(mx, result[i][j][k]);
                if (result[i][j][k]==0&&board[i][j][k]==0)
                {
                    flag=false;
                }
            }
        }
    }

    if (flag)    cout<<mx;
    else cout<<"-1";
}