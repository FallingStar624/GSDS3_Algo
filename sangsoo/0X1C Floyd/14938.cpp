#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n, m, r;
int item[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> item[i];
    }
    for(int i = 1; i <=n ; i++)
        fill(d[i], d[i]+1+n, INF);
    while(r--){ // 양방향 그래프라서 아까와 다름
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);  // 여러 노선이 있을 수 있음
        d[b][a] = min(d[b][a], c);  // 여러 노선이 있을 수 있음
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;

    for(int k = 1; k <= n; k++) // 제일 밖에 k가 위치
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    int mx = 0; int sum = 0;
    for(int i = 1; i <= n; i++){
        sum = 0; // reset
        for(int j = 1; j <= n; j++){
            if(d[i][j] == INF) continue;
            else{
                if(d[i][j] <= m){
                    sum += item[j] ;
                }
            }
        }
        if(mx < sum) mx = sum;
    }
    cout << mx;
}