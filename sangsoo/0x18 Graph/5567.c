#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 502

int adj[MAX_NODES][MAX_NODES];
int adjSize[2000];
int vis[MAX_NODES];
int lv[MAX_NODES];

int bfs(int v, int mx_lv){
    int q[MAX_NODES];
    int front = 0, rear = 0;
    q[rear++] = v;
    vis[v] = 1;
    lv[v] = 0;
    int cnt = 0;
    while (front < rear){
        int cur = q[front++];
        for(int i = 0; i < adjSize[cur]; i++){
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            if (lv[cur] == mx_lv) return cnt;
            vis[nxt] = 1;
            q[rear++] = nxt;
            cnt++;
            lv[nxt] = lv[cur] + 1;
        }
    }
    return cnt;
}


int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][adjSize[a]++] = b;
        adj[b][adjSize[b]++] = a;
    }
    printf("%d", bfs(1, 2));
}