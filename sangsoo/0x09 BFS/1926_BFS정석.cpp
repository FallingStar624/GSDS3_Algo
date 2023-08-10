// BFS 기본문제 flood fill
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해 사용
int board[502][502]; 
int vis[502][502]; // 전역으로 설정하면 0으로 초기화됨
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 0이 배경, 1 이 그림

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < m ; j++)
            cin >> board[i][j];
    int mx = 0; // 그림의 최댓값
    int num = 0; // 그림의 수
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < m ; j++){
            if(board[i][j] == 0 || vis[i][j]) continue; // 해당 칸이 색칠이 안된 부분이거나 이미 (i, j)를 방문했을 경우 넘어감
            num++; // 그림의 수 1 증가
            queue<pair<int, int>> q;
            vis[i][j] = 1; // visit 표시
            q.push({i, j});
            int area = 0; // 그림의 넓이
            while (!q.empty()){
                area++; // q에 들어있는 원소를 하나 뺄때마다 넓이를 1 증가
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir <4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0||nx >= n || ny < 0||ny >= m) continue; // 범위 밖이면 넘어감
                    if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문했거나 그림이 아닌경우
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            mx = max(mx, area); // area가 mx보다 큰 경우에 mx를 area에 대입
        }
    }
    cout << num << '\n' << mx;
}