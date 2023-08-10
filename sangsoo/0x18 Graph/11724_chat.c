#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int adj[1001][1001];
int adjSize[1001];
bool vis[1001];

int main(){
    int v, e;
    scanf("%d %d", &v, &e);

    for(int i = 1; i <= v; i++) {
        adjSize[i] = 0;
    }

    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][adjSize[a]++] = b;
        adj[b][adjSize[b]++] = a;
    }

    //BFS
    int num = 0;

    for(int i = 1; i <= v; i++){
        if(vis[i]) continue;
        vis[i] = true;
        num++;
        int* q = (int*)malloc(v * sizeof(int));
        int front = 0, back = 0;

        q[back++] = i;
        while(front != back){
            int cur = q[front++];
            for(int j = 0; j < adjSize[cur]; j++) {
                int n = adj[cur][j];
                if (vis[n]) continue;
                vis[n] = true;
                q[back++] = n;
            }
        }
        free(q);
    }
    printf("%d", num);
    return 0;
}
