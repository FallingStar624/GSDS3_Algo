#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
int visit[101][101];
int board[101][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
vector<int> result;

int main() {
    cin >> m >> n >> k;
    for (int i=0; i<k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int x=lx; x<rx; x++) {
             for (int y=ly; y<ry; y++) {
                 board[y][x] = 1;
             }
        }
    }
    queue <pair<int, int>> Q;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (visit[i][j]==0 && board[i][j]==0) {
                visit[i][j]=1;
                Q.push(make_pair(i, j));
                int res = 0;
                while (!Q.empty()) {
                    auto curr = Q.front();
                    Q.pop();
                    if (board[i][j]==0) {
                        res++;
                    }
                    for (int d=0; d<4; d++) {
                        int nr = curr.first + dr[d];
                        int nc = curr.second +dc[d];
                        if (-1<nr && nr<m && -1<nc && nc<n && visit[nr][nc]==0 && board[nr][nc]==0) {
                            Q.push(make_pair(nr, nc));
                            visit[nr][nc]=1;
                        }
                    }
                }
                result.push_back(res);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto i: result) {
        cout << i << " ";
    }
    return 0;
}
