#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, l;
int visit[301][301];
int dr[] = {2, 1, 2, 1, -2, -1, -2, -1};
int dc[] = {-1, -2, 1, 2, -1, -2,1, 2};

int bfs(int x, int y ,int fx, int fy) {
    queue<pair<pair<int, int>, int>> Q;
       Q.push(make_pair(make_pair(x,y), 0));
       visit[x][y] = 1;
       while (!Q.empty()) {
           auto curr = Q.front();
           Q.pop();
           if (curr.first.first == fx && curr.first.second == fy) return curr.second;
           for (int d=0; d<8; d++) {
               int nr = curr.first.first + dr[d];
               int nc = curr.first.second + dc[d];
               if (-1<nr && nr<l && -1<nc && nc<l && visit[nr][nc]==0) {
                   Q.push(make_pair(make_pair(nr, nc), curr.second+1));
                   visit[nr][nc] = 1;
               }
           }
       }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> l;
        int x, y, fx, fy;
        cin >> x >> y >> fx >> fy;
        cout << bfs(x, y, fx, fy) << endl;
        //초기화
        for (int a=0; a<l; a++) {
            for (int b=0; b<l; b++) {
                visit[a][b] = 0;
            }
        }
    }
    return 0;
}
