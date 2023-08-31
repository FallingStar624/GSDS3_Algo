#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f
#define MAXN 105

int d[MAXN][MAXN];
int nxt[MAXN][MAXN];
int n, m;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) {
                printf("0 ");
            } else {
                printf("%d ", d[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] == INF) {
                printf("0\n");
                continue;
            }
            
            int path[MAXN];
            int path_len = 0;
            int st = i;
            while (st != j) {
                path[path_len++] = st;
                st = nxt[st][j];
            }
            path[path_len++] = j;
            
            printf("%d ", path_len);
            for (int k = 0; k < path_len; k++) {
                printf("%d ", path[k]);
            }
            printf("\n");
        }
    }

    return 0;
}
