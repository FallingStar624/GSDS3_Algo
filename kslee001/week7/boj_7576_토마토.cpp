#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define Y first
#define X second

int board[1002][1002];
int dist[1002][1002];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int ny;
int nx;
int n, m;

int main(){
    cin >>m>>n;
    queue<pair<int,int>> que;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1){
                que.push({i,j});    
            }
            if(board[i][j] ==0){
                dist[i][j] = -1;
            }
        }
    }


    while(!que.empty()){
        auto cur = que.front(); que.pop();
        for(int d = 0; d<4; ++d){
            ny = cur.Y + dy[d];
            nx = cur.X + dx[d];
            if(nx <0 || nx >=m || ny <0 || ny >=n){
                continue;
            }
            if(dist[ny][nx]>= 0) continue;
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            que.push({ny,nx});
        }
    }

    int res =0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    }


    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << res;


}
