#include <bits/stdc++.h>
using namespace std;
#define X first // pair 에서 first, second를 줄여서 쓰기 위해서 사용
#define Y second
int board[502][502]; 
bool vis[502][502]; // 방문 칸 확인
int dist[502][502]; // 거리측정용 보드
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){ // 주어진 행렬(?) 저장
        string row;
        cin >> row;
        /// cout << "row[i]"<< row[i] << endl;
        for (int j = 0; j < m; j++){
            //cout << "i : " << i << " j : " << j << '\n';
            //cout << "row : " << row << "  " << "row[j] : " << row[j] << '\n';
            board[i][j] = row[j]-'0'; // 문자형태여서 숫자로 변환하기 위해 '0'을빼줌 아마 아스키코드인듯?
            //cout << "board[i][j]: " << board[i][j] << '\n';
        }
    }
    int length = 0;
    queue<pair<int, int>> Q;
    vis[0][0] = 1; // 시작점을 방문했다고 명시
    dist[0][0] = 1; // 시작점을 포함한 거리 이므로 1로 초기화
    Q.push({0, 0}); // 큐에 시작점인 (0, 0)을 삽입
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        //cout << "cur : " << cur.X << " " << cur.Y << '\n';
        //cout << "dist[cur.X][cur.Y]: " << dist[cur.X][cur.Y] << '\n';
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            //cout << "nx : " << nx << " ny : " << ny << '\n';
            //cout << "vis[nx][ny] : " << vis[nx][ny] << " board[nx][ny] : " << board[nx][ny] << '\n';
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // 이미 방문한 칸이거나 길이 아닌경우 넘어감
            vis[nx][ny] = 1; //(nx, ny)를 방문했다고 명시
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] +1;
        }
    }
    cout << dist[n-1][m-1];
}
