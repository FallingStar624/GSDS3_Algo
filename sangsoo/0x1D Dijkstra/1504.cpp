// 플로이드와샬 문제가 왜 다익스트라에....?
#include <iostream>
using namespace std;

const int INF = 0x1f3f3f3f; // overflow가 날수 있어서 0x1f3f3f3f 로 해야함.
int d[1001][1001];
int t[1001];
int n, m, v1, v2;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fill(d[i], d[i]+1+n, INF);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }
    cin >> v1 >> v2;
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    int path1 = d[1][v1]+d[v1][v2]+d[v2][n];
    int path2 = d[1][v2]+d[v2][v1]+d[v1][n];
    int mnpath = path1 < path2 ? path1 : path2;
    if (mnpath >= INF) cout << -1;
    else cout << mnpath ;   
}