#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K,N,M;
int board[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int visited[102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin>>M>>N>>K; // 5 7
    int left_x,left_y,right_x,right_y;
    while (K--) {
        cin >> left_x >> left_y >> right_x >> right_y;
        for (int i = left_x; i < right_x; i++) {
            for (int j = left_y; j < right_y; j++) {
                board[j][i] = 1;
            }
        }
    }
    queue<pair<int, int>> Q;
    vector<int> resul;
    int cnt=0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]==1||board[i][j]==1) continue;
            else {
                int area=0;
                cnt++;
                Q.push({i,j});
                visited[i][j]=1;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
                        if (visited[nx][ny]==1 || board[nx][ny] == 1)continue;
                        visited[nx][ny]=1;
                        Q.push({nx, ny});
                    }
                }
                resul.push_back(area);
            }
        }
    }
    sort(resul.begin(), resul.end());
    cout<<cnt<<'\n';
    for (int i=0;i<cnt;i++) cout<<resul[i]<<' ';
}