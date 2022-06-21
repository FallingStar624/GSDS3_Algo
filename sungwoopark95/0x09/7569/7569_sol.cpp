#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int box[MAX][MAX][MAX];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    queue<array<int, 4>> Q;
    
    int height, width, depth;
    cin >> width >> height >> depth;
    
    for (int h=0;h<depth;h++) {
        for (int i=0;i<height;i++) {
            for (int j=0;j<width;j++) {
                cin >> box[h][i][j];
                if (box[h][i][j] == 1) { Q.push({h, i, j, box[h][i][j]}); }
            }
        }
    }    

    while (!Q.empty()) {
        array<int, 4> curr = Q.front(); Q.pop();
        if (box[curr[0]][curr[1]][curr[2]] < 0 || box[curr[0]][curr[1]][curr[2]] > 1) { continue; }
        box[curr[0]][curr[1]][curr[2]] = curr[3];
        for (int dir=0;dir<6;dir++) {
            int nx = curr[1] + dx[dir];
            int ny = curr[2] + dy[dir];
            int nz = curr[0] + dz[dir];
            if (nx < 0 || nx >= height || ny < 0 || ny >= width || nz < 0 || nz >= depth) { continue; }
            if (box[nz][nx][ny] != 0) { continue; }
            Q.push({nz, nx, ny, curr[3]+1});
        }
    }

    int time = 0;
    for (int h=0;h<depth;h++) {
        for (int i=0;i<height;i++) {
            for (int j=0;j<width;j++) {
                if (box[h][i][j] == 0) {
                    cout << -1 << "\n";
                    return 0;
                } else if (box[h][i][j] > 0) {
                    time = max(time, box[h][i][j]);
                }
            }
        }
    }

    cout << time-1 << "\n";
    return 0;
}