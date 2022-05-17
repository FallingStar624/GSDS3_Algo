#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c;
int J[1001][1001];
int F[1001][1001];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin >> r >> c;
    pair<int, int> start_j;
    pair<int, int> start_f;
    queue<pair<int, int>> QJ;
    queue<pair<int, int>> QF;
    for (int i=0;i<r; i++) {
        string tmp; cin >> tmp;
        for (int j=0; j<c; j++) {
            if (tmp[j]=='#') {
                //벽
                J[i][j] = -1;
                F[i][j] = -1;
            } else if (tmp[j]=='J') {
                J[i][j] = 1;
                F[i][j] = 1000001;
                QJ.push(make_pair(i,j));
            } else if (tmp[j]=='F') {
                J[i][j] = 1000001;
                F[i][j] = 1;
                QF.push(make_pair(i,j));
            } else {
                J[i][j] = 1000001;
                F[i][j] = 1000001;
            }
        }
    }
    while (!QF.empty()) {
        auto curr = QF.front();
        QF.pop();
        for (int d=0; d<4; d++) {
            int nr = curr.first + dr[d];
            int nc = curr.second + dc[d];
            if (-1<nr && nr<r && -1<nc && nc<c && F[nr][nc]==1000001) {
                QF.push(make_pair(nr,nc));
                F[nr][nc]=F[curr.first][curr.second]+1;
            }
        }
    }
    while (!QJ.empty()) {
        auto curr = QJ.front();
        QJ.pop();
        for (int d=0; d<4; d++) {
            int nr = curr.first + dr[d];
            int nc = curr.second + dc[d];
            if (-1>=nr || r<=nr || -1>=nc || c<=nc) {
                cout << J[curr.first][curr.second];
                return 0;
            }
            if (-1<nr && nr<r && -1<nc && nc<c && J[nr][nc]==1000001) {
                if (J[curr.first][curr.second]+1 < F[nr][nc]) {
                    QJ.push(make_pair(nr,nc));
                    J[nr][nc]=J[curr.first][curr.second]+1;
                } else {
                    J[nr][nc] = -1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
