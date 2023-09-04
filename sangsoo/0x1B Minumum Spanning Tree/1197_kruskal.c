#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 10005
#define MAX_EDGES 100005

int parent[MAX_NODES];
typedef struct {
    int weight;
    int u, v;
} Edge;

Edge edges[MAX_EDGES];

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(int x) {
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); 
    v = find(v);
    
    if(u == v) return false;
    if(parent[u] == parent[v]) parent[u]--;
    if(parent[u] < parent[v]) parent[v] = u;
    else parent[u] = v;
    return true;
}

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    for(int i = 0; i < MAX_NODES; i++) {
        parent[i] = -1;
    }

    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    qsort(edges, e, sizeof(Edge), compare);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++) {
        if(!is_diff_group(edges[i].u, edges[i].v)) continue;
        ans += edges[i].weight;
        cnt++;
        if(cnt == v-1) break;    
    }

    printf("%d\n", ans);
    return 0;
}
