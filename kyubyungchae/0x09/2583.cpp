#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    cout << "\n";
    while(k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int width, height;
        width = x2 - x1;
        height = y2 - y1;

        // initial point
        int row, col;
        row = m - y1 - height;
        col = x1;

        for(int i = row; i < row + height; i++) {
            for(int j = col; j < col + width; j++) {
                board[i][j] = 1;
            }
        }
    }

    int count = 0;
    vector<int> ans;

    

    
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    int tot = 0;
    int area = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == -1) continue;

            if(visited[i][j]) continue;
            tot++;            
            dfs(i, j, area);
            arr[tot] = area;
        }
    }
    cout << tot << "\n";
    for(int i = 0; i < tot; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


void dfs(int nx, int ny, int &area) {

    if(nx < 0 || nx >= n || ny < 0 || ny >= m) return;
    if(visited[nx][ny] || board[nx][ny] == -1) return;

    visited[nx][ny] = true;
    area++;
    cout << *area;
    dfs(nx, ny+1, area);
    dfs(nx, ny-1, area);
    dfs(nx-1, ny, area);
    dfs(nx+1, ny, area);

    return;
}


