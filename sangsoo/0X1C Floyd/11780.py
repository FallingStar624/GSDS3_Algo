import sys
input = sys.stdin.readline

INF = float('inf')
MAXN = 105

n = int(input())
m = int(input())

d = [[INF for _ in range(MAXN)] for _ in range(MAXN)]
nxt = [[0 for _ in range(MAXN)] for _ in range(MAXN)]

for _ in range(m):
    a, b, c = map(int, input().split())
    d[a][b] = min(d[a][b], c)
    nxt[a][b] = b

for i in range(1, n+1):
    d[i][i] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if d[i][j] > d[i][k] + d[k][j]:
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])
                nxt[i][j] = nxt[i][k]

for i in range(1, n+1):
    for j in range(1, n+1):
        if d[i][j] == INF:
            print("0 ", end="")
        else:
            print(d[i][j], end=" ")
    print()

for i in range(1, n+1):
    for j in range(1, n+1):
        if d[i][j] == 0 or d[i][j] == INF:
            print("0")
            continue
        
        path = []
        st = i
        while st != j:
            path.append(st)
            st = nxt[st][j]
        path.append(j)
        
        print(len(path), end=" ")
        for p in path:
            print(p, end=" ")
        print()
