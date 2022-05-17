#include <bits/stdc++.h>

using namespace std;

#define MAXN (100004)

queue<int> Q;
int N, K;
int dist[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + MAXN - 1, -1);
    cin >> N >> K;
    Q.push(N);
    dist[N] = 0;
    while (!Q.empty()) {
        int curr = Q.front(); Q.pop();
        if (curr == K) {
            cout << dist[curr];
            return 0;
        }
        int next[3] = {curr - 1, curr + 1, curr * 2};
        for (int i = 0; i < 3; ++i) {
            if (next[i] < 0 || next[i] >= MAXN) continue;
            if (dist[next[i]] != -1) continue;
            Q.push(next[i]);
            dist[next[i]] = dist[curr] + 1;
        }
    }

    return 0;
}