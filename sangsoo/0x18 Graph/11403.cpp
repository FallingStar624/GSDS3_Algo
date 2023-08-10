#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int adj[102][102];
int vis[102];
int path[102][102];
void *naive_memset(void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}

int bfs(int st, int en, int v){ // st: 시작 노드  en: 끝 노드 v: 총 노드 수
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    naive_memset(vis, 0, sizeof(int)*v); // memset 할때는 반드시 sizeof(int)붙여야함 // naive_ 떼고 memset으로 해도 돌아감.
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt = 0; nxt < v; nxt++){
            if(vis[nxt]) continue;
            if(!adj[cur][nxt]) continue; // 경로가 없으면 continue
            vis[nxt] = 1;
            q.push(nxt);
            if (nxt == en) return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << bfs(i, j, n) << " ";
        }
        cout << "\n";
    }
}