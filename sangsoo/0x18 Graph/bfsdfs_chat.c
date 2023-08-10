#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

int adj[MAX_NODES][MAX_NODES];
int edge_count[MAX_NODES];
bool vis[MAX_NODES];
int dist[MAX_NODES];

// BFS traversal for a connected graph, starting node v
void bfs_traverse(int v) {
    int q[MAX_NODES];
    int front = 0, rear = 0;
    q[rear++] = v;
    vis[v] = true;
    while (front < rear) {
        int cur = q[front++];
        printf("%d ", cur);
        for (int i = 0; i < edge_count[cur]; i++) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q[rear++] = nxt;
        }
    }
    printf("\n");
}

// BFS for distances in a connected graph from vertex V
void bfs_dist(int v) {
    int q[MAX_NODES];
    int front = 0, rear = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = -1;
    }
    q[rear++] = v;
    dist[v] = 0;
    while (front < rear) {
        int cur = q[front++];
        for (int i = 0; i < edge_count[cur]; i++) {
            int nxt = adj[cur][i];
            if (dist[nxt] != -1) continue;
            q[rear++] = nxt;
            dist[nxt] = dist[cur] + 1;
        }
    }
}

// DFS traversal for a connected graph, non-recursive version, starting node v
void dfs(int v) {
    int s[MAX_NODES];
    int top = 0;
    s[top++] = v;
    while (top > 0) {
        int cur = s[--top];
        if (vis[cur]) continue;
        vis[cur] = true;
        printf("%d ", cur);
        for (int i = edge_count[cur] - 1; i >= 0; i--) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            s[top++] = nxt;
        }
    }
    printf("\n");
}

// DFS traversal for a connected graph, recursive version
void dfs_recursive(int cur) {
    vis[cur] = true;
    printf("%d ", cur);
    for (int i = 0; i < edge_count[cur]; i++) {
        int nxt = adj[cur][i];
        if (vis[nxt]) continue;
        dfs_recursive(nxt);
    }
}

// To use these functions, fill the adj matrix and edge_count array accordingly.

int main() {
    // Example usage here...
    return 0;
}
