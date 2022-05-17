#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
string tmp;
int board[100][100];
int dists[100][100];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin>> n >> m;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        for (int j=0; j<m; j++) {
            board[i][j] = int(tmp[j]) - 48;
            dists[i][j] = 10001;
        }
    }
    pair<pair<int, int>, int> start = make_pair(make_pair(0, 0), 1);
    queue<pair<pair<int, int>, int>> Q;
    Q.push(start);
    while(!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        if (board[curr.first.first][curr.first.second]==1) {
            if (dists[curr.first.first][curr.first.second] > curr.second){
                dists[curr.first.first][curr.first.second] = curr.second;
                for (int d=0; d<4; d++) {
                    int nr = curr.first.first + dr[d];
                    int nc = curr.first.second + dc[d];
                    if (0<= nr && nr < n && 0<=nc && nc < m && board[nr][nc]==1){
                        Q.push(make_pair(make_pair(nr,nc), curr.second+1));
                    }
                }
            } else {
                continue;
            }
        }
    }
    cout << dists[n-1][m-1];
    return 0;
}
