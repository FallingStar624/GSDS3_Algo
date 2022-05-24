#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, m, n, k;
int field[51][51];
int visit[51][51];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs() {
    int ans=0;
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
           if (visit[i][j]==0 && field[i][j]==1) {
               ans++;
               Q.push(make_pair(i,j));
               visit[i][j] = 1;
               while (!Q.empty()) {
                   auto curr = Q.front();
                   Q.pop();
                   for (int d=0; d<4; d++) {
                       int nr = curr.first + dr[d];
                       int nc = curr.second + dc[d];
                       if (-1<nr && nr<n && -1<nc && nc<m && visit[nr][nc]==0 && field[nr][nc] == 1) {
                           Q.push(make_pair(nr, nc));
                           visit[nr][nc] = 1;
                       }
                   }
               }
           }
            while (!Q.empty()) Q.pop();
        }
    }
    return ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> m >> n >> k;
        for (int j=0; j<k; j++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }
        cout << dfs() << endl;
        for (int a=0; a<n; a++) {
            for (int b=0; b<m; b++) {
                field[a][b] = 0;
                visit[a][b] = 0;
            }
        }
    }
    return 0;
}
