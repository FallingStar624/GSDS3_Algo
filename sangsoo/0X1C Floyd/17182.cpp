#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int d[202][202];
int vis[202];
int n, m;
int result = INF;

void dfs(int idx, int planet, int dist){
    if(planet == n){ // 모든 행성 방문 완료 시
        result = min(result, dist); // 최소 값 갱신
        return;
    }
    for(int i = 0; i < n; i ++){
        if(vis[i]) continue; // 방문 행성 무시
        vis[i] = 1;
        dfs(i, planet+1, dist + d[idx][i]); // backtracking
        vis[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> d[i][j];
    
    // 플로이드 와샬
    for(int k = 0; k < n; k++) // 거쳐가는 노드
        for(int i = 0; i < n; i++) // 출발 노드
            for(int j = 0; j < n; j++) // 도착 노드
                if(d[i][j] > d[i][k] + d[k][j]) // 더 작은 값
                    d[i][j] = d[i][k] + d[k][j];

    vis[m] = 1; // 시작점 방문 체크
    dfs(m, 1, 0);
    cout << result;
}