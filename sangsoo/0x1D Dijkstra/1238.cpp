// 플로이드와샬 문제가 왜 다익스트라에....?
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[1001][1001];
int t[1001];
int n, m, x;
int main(){
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++)
        fill(d[i], d[i]+1+n, INF);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        t[i] = d[i][x] + d[x][i];
        if(mx < t[i]) mx = t[i];
    }
    cout << mx ;   
}