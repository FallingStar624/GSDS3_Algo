#include <bits/stdc++.h>
using namespace std;
#define MAX 200000

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int dist[MAX];
    for (int i=0;i<MAX;i++) {
        dist[i] = -1;
    }

    int N, K;
    cin >> N >> K;

    dist[N] = 0;
    queue<int> Q;
    Q.push(N);
    while (dist[K] == -1) {
        int curr = Q.front();
        Q.pop();
        for (int next : {curr-1, curr+1, 2*curr}) {
            if (next < 0 || next > MAX) { continue; }
            if (dist[next] >= 0) { continue; }
            dist[next] = dist[curr] + 1;
            Q.push(next);
        }
    }

    cout << dist[K] << "\n";
    return 0;
}