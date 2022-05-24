#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
string pic[101];
int visit[101][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int normal() {
    int ans=0;
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
           if (visit[i][j]==0) {
               ans++;
               Q.push(make_pair(i,j));
               visit[i][j] = 1;
               char tmp = pic[i][j];
               while (!Q.empty()) {
                   auto curr = Q.front();
                   Q.pop();
                   for (int d=0; d<4; d++) {
                       int nr = curr.first + dr[d];
                       int nc = curr.second + dc[d];
                       if (-1<nr && nr<n && -1<nc && nc<n && visit[nr][nc]==0 && pic[nr][nc] == tmp) {
                           Q.push(make_pair(nr, nc));
                           visit[nr][nc] = 1;
                       }
                   }
               }
           }
        }
       while (!Q.empty()) Q.pop();
    }
    return ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> pic[i];
    }
    cout << normal() << " ";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visit[i][j] = 0;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (pic[i][j]=='R') pic[i][j]='G';
        }
    }
    cout << normal();

    return 0;
}
