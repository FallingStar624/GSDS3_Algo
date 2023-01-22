#include <bits/stdc++.h>
using namespace std;
#define X first // pair 에서 first, second를 줄여서 쓰기 위해서 사용
#define Y second
int board[1002][1002]; 
bool vis[1002][1002] = {0}; // 방문 칸 확인
int dist[1002][1002] = {0}; // 거리측정용 보드 0으로 초기화
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int num_max = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; // 가로세로가 반대로되어있어서 많이 틀림
    for (int i = 0; i < m; i++){ // 주어진 행렬(?) 저장
        for (int j = 0; j < n; j++){
            cin >> board[i][j];  
        }
    }

    // for (int i = 0; i < m; i++){ // 주어진 행렬(?) 출력
    //     for (int j = 0; j < n; j++){
    //         cout << board[i][j];  
    //     }
    //     cout << endl;
    // }

    queue<pair<int, int>> Q;
    for (int i = 0 ; i <m; i++){
        for (int j = 0; j < n; j++){
            if (vis[i][j] == 0 && board[i][j] == 1){ // 여러개의 시작점에서 진행
                vis[i][j] = 1; // 시작점을 방문했다고 명시
                Q.push({i, j}); // 큐에 시작점인 (i, j)을 삽입
                }
            }
        }
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        vis[cur.X][cur.Y] = 1; // 방문했다고 명시    
        //cout << "cur.X : " <<cur.X << " cur.Y : " <<cur.Y << endl; 
        Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] == 1 || board[nx][ny] == -1) continue; // 이미 방문한 칸이거나 그림이 아닌경우 넘어감
            vis[nx][ny] = 1; //(nx, ny)를 방문했다고 명시
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            if (num_max < dist[nx][ny]) num_max = dist[nx][ny];
            //cout << "nx : " << nx << ", " << "ny : " << ny << endl;
            //cout << "board[nx][ny] : " << board[nx][ny] << "dist[nx][ny] : " << dist[nx][ny] << endl;
            //cout << "num_max : "<< num_max << endl;
            }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j <n; j++){
            if (vis[i][j] == 0 && board[i][j] != -1){
                //cout <<"i : " << i << "  j : " << j << endl;
                num_max = -1;
            }
        }
    }
    cout << num_max;
    return 0;
}
