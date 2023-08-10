#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 102

int adj[MAX_NODES][MAX_NODES];
int adjSize[2000];
int vis[MAX_NODES];
int dist[MAX_NODES];

int bfs(int v){
    int q[MAX_NODES];
    int front = 0, rear = 0;
    q[rear++] = v;
    vis[v] = 1;
    int cnt = 0;
    while (front < rear){
        int cur = q[front++];
        for(int i = 0; i < adjSize[cur]; i++){
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            q[rear++] = nxt;
            cnt++;
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
    printf("%d", bfs(1));
}