#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용


int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool visit[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향 표시

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> q;
    visit[0][0] = 1; // (0,0)을 방문했다고 명시
    q.push({0,0});

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];  // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(visit[nx][ny] || board[nx][ny] != 1) // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                continue;
            visit[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return 0;
}