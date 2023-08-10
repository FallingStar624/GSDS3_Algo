#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1001

int adj[MAX_NODES][MAX_NODES];
int adjSize[MAX_NODES];
bool vis[MAX_NODES];
int dist[MAX_NODES];

void bfs(int v) {
    int q[MAX_NODES];
    int front = 0, rear = 0;
    q[rear++] = v;
    vis[v] = true;
    while (front < rear) {
        int cur = q[front++];
        printf("%d ", cur);
        for (int i = 0; i < adjSize[cur]; i++) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q[rear++] = nxt;
        }
    }
    printf("\n");
}

void dfs1(int v) {
    int s[MAX_NODES];
    int top = 0;
    s[top++] = v;
    while (top > 0) {
        int cur = s[--top];
        if (vis[cur]) continue;
        vis[cur] = true;
        printf("%d ", cur);
        for (int i = adjSize[cur] - 1; i >= 0; i--) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            s[top++] = nxt;
        }
    }
}

void dfs2(int cur) {
    vis[cur] = true;
    printf("%d ", cur);
    for (int i = 0; i < adjSize[cur]; i++) {
        int nxt = adj[cur][i];
        if (vis[nxt]) continue;
        dfs2(nxt);
    }
}

void merge(int a[], int first, int mid, int last){
    int i = first, j = mid+1, k = 0;
    int size = last - first + 1;
    int *tmp = (int*) malloc(sizeof(int) * size);

    while (i <= mid && j <= last){
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    } 
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= last) tmp[k++] = a[j++];

    // Copy tmp array back to a
    for(i = 0; i < size; i++) {
        a[first + i] = tmp[i];
    }
    free(tmp);
}

void mergeSortHelp(int a[], int first, int last){
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelp(a, first, mid);
        mergeSortHelp(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

int main(){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v); // n :노드개수, m: edge개수, v :시작 노드
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][adjSize[a]++]=b;
        adj[b][adjSize[b]++]=a;
    }

    for(int i = 1; i <= n; i++){
        int size_adj = adjSize[i];
        mergeSortHelp(adj[i], 0, size_adj-1);
    }
    dfs2(v);
    printf("\n");
    memset(vis, 0, sizeof(bool)*(n+1));
    bfs(v);
}