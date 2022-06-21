#include <bits/stdc++.h>
using namespace std;
#define MAX 52

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int farm[MAX][MAX];
bool visited[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
        int N, M, B; // B: the number of baechoo
        cin >> M >> N >> B;
        for (int i=0;i<MAX;i++) {
            for (int j=0;j<MAX;j++) {
                farm[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        for (int i=0;i<B;i++) {
            int j, k;
            cin >> j >> k;
            farm[j][k] = 1;
        }

        // BFS
        int worm = 0;
        queue<pair<int, int>> Q;
        for (int i=0;i<M;i++) {
            for (int j=0;j<N;j++) {
                if (farm[i][j] == 0 || visited[i][j] == 1) { continue; }
                worm++;
                visited[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    pair<int, int> coord = Q.front();
                    Q.pop();
                    // 이웃 방문 시작
                    for (int i=0;i<4;i++) {
                        int nx = coord.first + dx[i];
                        int ny = coord.second + dy[i];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) { continue; }
                        if (farm[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }
                        visited[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << worm << "\n";
    }

    return 0;
}