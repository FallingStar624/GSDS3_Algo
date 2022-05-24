#include <bits/stdc++.h>
using namespace std;

int visited[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    pair<int, int> coord;
    queue< pair<int, int> > Q;

    int width, height;
    cin >> width >> height;
    int matrix[width][height];
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    // 탐색 시작
    int max_area = 0;
    int num_pics = 0;
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            if (matrix[i][j] == 0 || visited[i][j] == 1) { continue; }
            num_pics++;
            visited[i][j] = 1;
            Q.push({i, j});
            int area = 1;
            while (!Q.empty()) {
                coord = Q.front();
                Q.pop();
                // 이웃 방문 시작
                for (int i=0;i<4;i++) {
                    int nx = coord.first + dx[i];
                    int ny = coord.second + dy[i];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height) { continue; }
                    if (matrix[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }
                    area++; // 넓이 더해줌
                    visited[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            max_area = max(max_area, area);
        }
    }
    cout << num_pics << "\n" << max_area << "\n";
    return 0;
}