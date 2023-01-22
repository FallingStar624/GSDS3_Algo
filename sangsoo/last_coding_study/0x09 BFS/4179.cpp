#include <bits/stdc++.h>
using namespace std;
#define X first // pair 에서 first, second를 줄여서 쓰기 위해서 사용
#define Y second
char board[1002][1002]; 
bool vis[1002][1002]; // 방문 칸 확인
bool f_vis[1002][1002]; // 불 방문 칸 확인
int time_board[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<int> q;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){ // 주어진 행렬(?) 저장
        string row;
        cin >> row;
        // cout << "row : "<<row<< endl;        
        // cout << "m : "<< m << endl;
        for (int j = 0; j < m; j++){
            // cout << "i : " << i << " j : " << j << '\n';
            // cout << "row : " << row << "  " << "row[j] : " << row[j] << '\n';
            board[i][j] = row[j]; 
            // cout << "board[i][j]: " << board[i][j] << '\n';
        }
    }


    int time = 0;

    queue<pair<int, int>> Q;
    queue<pair<int, int>> FQ;
    for (int i = 0 ; i <n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 'J'){ // 'j'에서 시작
                // cout << "i : " << i << " j : " << j <<" tmp_area : " << tmp_area << " pict_num : " << pict_num << '\n';
                vis[i][j] = 1; // 시작점을 방문했다고 명시
                Q.push({i, j}); // 큐에 시작점인 (i, j)을 삽입
                if(i == n-1|| i == 0 || j == m-1 || j == 0) q.push(0); //J가 가장자리에 있을 경우
            }
            if (board[i][j] == 'F'){ // 'j'에서 시작
                // cout << "i : " << i << " j : " << j <<" tmp_area : " << tmp_area << " pict_num : " << pict_num << '\n';
                f_vis[i][j] = 1; // 불 시작점을 방문했다고 명시
                FQ.push({i, j}); // 큐에 시작점인 (i, j)을 삽입
            }
        }
    }
    while(!Q.empty()){
        pair<int, int> fcur = FQ.front(); FQ.pop();
        pair<int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++){
            int fnx = fcur.X + dx[dir];
            int fny = fcur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            //cout << "11fnx : " << fnx << "fny : " << fny << endl;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] == 1 || board[nx][ny] == '#'|| board[nx][ny] == 'F') continue; // 이미 방문한 칸이거나 벽이면 넘어감
            vis[nx][ny] = 1; //(nx, ny)를 방문했다고 명시
            Q.push({nx, ny});
            time_board[nx][ny] = time_board[cur.X][cur.Y]+1;
            if(nx == n-1|| nx == 0 || ny == m-1 || ny == 0){
                // cout << "nx: " << nx << " ny: " << ny << endl;
                // cout << "time_board[nx][ny] : " << time_board[nx][ny] << endl; 
                q.push(time_board[nx][ny]);
            }
            // 불에대해서 bfs
            if (fnx < 0 || fnx >= n || fny < 0 || fny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[fnx][fny] == 1 || board[fnx][fny] == '#'|| board[fnx][fny] == 'F') continue; // 이미 방문한 칸이거나 벽이면 넘어감
            f_vis[fnx][fny] = 1; //(nx, ny)를 방문했다고 명시
            board[fnx][fny] = 'F'; // 불이 번지는 것을 명시
            FQ.push({fnx, fny});
            //cout << "fnx : " << fnx << "fny : " << fny << endl;
            
        }
    }
    if(q.empty()) cout << "IMPOSSIBLE";
    else cout << q.front()+1;
} 
        
    

