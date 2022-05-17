#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int cnt = 0;
int length = 0;
int result = 0;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int arr[500][500];
bool visit[500][500];

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            visit[i][j] = false;
        }
    }
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j]==1 && !visit[i][j]) {
                Q.push(make_pair(i,j));
                cnt ++;
            }
            length = 0;
            while (!Q.empty()) {
                auto curr = Q.front();
                Q.pop();
                if (arr[curr.first][curr.second]==1 && !visit[curr.first][curr.second]) {
                    visit[curr.first][curr.second] = true;
                    ++length;
                    for (int d=0; d<4 ; d++) {
                        int nr = curr.first + dr[d];
                        int nc = curr.second + dc[d];
                        if (0 <= nr && nr < n && 0 <= nc && nc < m && !visit[nr][nc]) {
                            Q.push(make_pair(nr, nc));
                        }
                    }
                } else {
                    continue;
                }
            }
            result = max(result, length);
        }
    }
    cout << cnt << endl;
    cout << result << endl;
    return 0;
}
