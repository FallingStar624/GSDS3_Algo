#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, tmp, cnt, result;
int board[1001][1001];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>> m >> n;
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
            if (board[i][j]==1) {
                Q.push(make_pair(i,j));
            }
            if (board[i][j]==0) {
                cnt++;
            }
        }
    }

    while (!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        result = max(board[curr.first][curr.second], result);
        for (int d=0; d<4; d++) {
            int nr = curr.first + dr[d];
            int nc = curr.second + dc[d];
            if (0<=nr && nr<n && 0<=nc && nc<m && board[nr][nc]==0) {
                Q.push(make_pair(nr, nc));
                board[nr][nc] = board[curr.first][curr.second] + 1;
            }
        }
    }

    result--;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 0) {
                result = -1;
                break;
            }
        }
    }
    if (cnt==0) {
        result = 0;
    }
    cout << result;
    return 0;
}
