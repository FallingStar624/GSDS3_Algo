#include <bits/stdc++.h>
using namespace std;
#define X first // pair 에서 first, second를 줄여서 쓰기 위해서 사용
#define Y second
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502];
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vis[0][0] = 1; // (0,0)을 방문했다고 명시
    Q.push({0, 0}); // 큐에 시작점인 (0, 0)을 삽입 
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란칸이 아닌경우
            vis[nx][ny] = 1; //(nx, ny)를 방문했다고 명시
            Q.push({nx, ny}); 
        }
    }
}

