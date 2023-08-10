#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1002

int adj[MAX_NODES][MAX_NODES];
int adjSize[20000];
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
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
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


    // 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
    for(int i=1; i<=n;i++){
        qsort(adj[i], adjSize[i], sizeof(int), compare);
    }
    dfs1(v);
    printf("\n");
    memset(vis, 0, sizeof(bool)*(n+1));
    bfs(v);
}