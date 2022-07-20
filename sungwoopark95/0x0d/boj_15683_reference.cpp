#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int N, M;
int office[10][10];
int office2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > vec;

// (dx[0], dy[0]) -> 오른쪽 방향
// (dx[1], dy[1]) -> 아래쪽 방향
// (dx[2], dy[2]) -> 왼쪽 방향
// (dx[3], dy[3]) -> 위쪽 방향

void search(int x, int y, int dir) {
    dir = dir % 4;
    // x, y position으로부터 dir 방향으로 옮기면서 0을 #으로 바꾸는 함수
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if (office2[x][y]==6 || x>=N || y>=M || x<0 || y<0) { return; }
        if (office2[x][y] != 0) { continue; }
        office2[x][y] = 7;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int cctv = 0;
    int zeros = 0;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            int item;
            cin >> item;
            office[i][j] = item;
            if (item>0 && item<6) { 
                cctv++; 
                vec.push_back({i, j});
            }
            if (item == 0) { zeros++; }
        }
    }

    int cases = 1 << (2*cctv); // 전체 경우의 수
    for (int k=0;k<cases;k++) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                office2[i][j] = office[i][j];
            }
        }
        
        int tmp = k;
        for (int i=0;i<(int)vec.size();i++) {
            int x = vec[i].first;
            int y = vec[i].second;
            int dir = tmp % 4;
            tmp = tmp / 4;
            if (office[x][y] == 1) {
                search(x, y, dir);
            }
            else if (office[x][y] == 2) {
                search(x, y, dir);
                search(x, y, dir+2);
            }
            else if (office[x][y] == 3) {
                search(x, y, dir);
                search(x, y, dir+1);
            }
            else if (office[x][y] == 4) {
                search(x, y, dir);
                search(x, y, dir+1);
                search(x, y, dir+2);
            }
            else if (office[x][y] == 5) {
                search(x, y, dir);
                search(x, y, dir+1);
                search(x, y, dir+2);
                search(x, y, dir+3);
            }
        }
        
        int cnt = 0;
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                if (office2[i][j] == 0) { cnt++; }
            }
        }
        
        zeros = min(zeros, cnt);
    }
    
    cout << zeros << "\n";
    return 0;
}