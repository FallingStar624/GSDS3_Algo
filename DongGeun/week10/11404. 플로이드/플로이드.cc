#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K,N,M;
int dist[102][102];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >>K>>N;
    for (int i=1;i<=K;i++) {
        for (int j = 1; j <= K; j++) {
            if (i != j) dist[i][j] = 100001*100;
        }
    }
    while (N--)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        dist[a][b]=min(dist[a][b],cost);
    }
    for (int i=1;i<=K;i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= K; k++) {
                if (j==k) dist[j][k]=0;
                else  dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for (int i=1;i<=K;i++) {
        for (int j = 1; j <= K; j++) {
            if (dist[i][j] == 100001*100||i==j) cout << 0 << ' ';
            else cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
}