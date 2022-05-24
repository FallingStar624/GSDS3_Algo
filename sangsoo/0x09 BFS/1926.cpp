#include <bits/stdc++.h>
using namespace std;
#define X first // pair 에서 first, second를 줄여서 쓰기 위해서 사용
#define Y second
int board[502][502]; 
bool vis[502][502]; // 방문 칸 확인
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){ // 주어진 행렬(?) 저장
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int pict_num = 0;
    int max_area = 0;
    int tmp_area = 0;
    queue<pair<int, int>> Q;
    for (int i = 0 ; i <n; i++){
        for (int j = 0; j < m; j++){
            if (vis[i][j] == 0 && board[i][j] == 1){ // 방문하지 않은 노드이고 그림에 대해서만 진행
                // cout << "i : " << i << " j : " << j <<" tmp_area : " << tmp_area << " pict_num : " << pict_num << '\n';
                vis[i][j] = 1; // 시작점을 방문했다고 명시
                Q.push({i, j}); // 큐에 시작점인 (i, j)을 삽입
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    tmp_area += 1; // queue 에서 하나 나올때 마다 tmp_area 1씩 증가
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // 이미 방문한 칸이거나 그림이 아닌경우 넘어감
                        vis[nx][ny] = 1; //(nx, ny)를 방문했다고 명시
                        Q.push({nx, ny});
                    }
                }
                // cout << " tmp_area : " << tmp_area << " pict_num : " << pict_num << '\n';
                if(max_area < tmp_area) max_area = tmp_area; tmp_area = 0; // 최댓값을 최신화 해주고, tmp_area를 초기화
                // cout << " max_area : " << max_area << '\n';
                pict_num += 1; // 그림 갯수 하나씩 추가
            } 
        }
    }
    cout << pict_num << '\n' << max_area;
}

