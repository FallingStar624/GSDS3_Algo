#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int arr[101][101];
int dist[101][101];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dijkstra() {
    priority_queue<tuple<int,int,int>> pq;
    dist[1][1] = 0;
    pq.push({0, 1, 1});
    while(!pq.empty()) {
        int cr = get<1>(pq.top());
        int cc = get<2>(pq.top());
        int c_dist = -get<0>(pq.top());
        pq.pop();
        if (c_dist > dist[cr][cc]) continue;
        for (int d=0; d<4; d++) {
            int nr = cr + dr[d];
            int nc = cc + dc[d];
            if (nr<=0 || nr > N || nc<=0 || nc >M) continue;
            int n_dist = c_dist + arr[nr][nc];
            if (n_dist < dist[nr][nc]) {
                dist[nr][nc] = n_dist;
                pq.push({-n_dist, nr, nc});
            }
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for (int i=1; i<=N; i++) {
        string str; cin >> str;
        for (int j=1; j<=M; j++) {
            arr[i][j] = str[j-1] - '0';;
            dist[i][j] = INF;
        }
    }
    dijkstra();
    cout << dist[N][M];
    return 0;
}
