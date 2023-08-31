#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, m, x, y, tmp;
int arr[101][101];
int visit[101][101];

void print_path(int i, int j, vector<int> &path) {
    if (visit[i][j] == -1) {
        path.push_back(i);
        path.push_back(j);
        return;
    }
    int stopover = visit[i][j];
    print_path(i, stopover, path);
    path.pop_back();
    print_path(stopover, j, path);
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] = INF;
            visit[i][j] = -1;
        }
    }
    for (int i=0; i<m ;i++) {
        cin >> x >> y >> tmp;
        if (tmp < arr[x][y]) arr[x][y] = tmp;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n ;i++) {
            for (int j=1; j<=n; j++) {
                if (i==j) continue;
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    visit[i][j] = k;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            tmp = arr[i][j];
            if (tmp < 987654321) {
                cout << tmp << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) {
                cout << 0;
            } else if (arr[i][j]==987654321) {
                cout << 0;
            } else {
                vector<int> path;
                print_path(i, j, path);
                cout << path.size() << " ";
                for (auto pt: path) {

