from sys import stdin
input = stdin.readline

INF = float('inf')

n = int(input())
m = int(input())

d = [[INF for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    d[a][b] = min(d[a][b], c)  # Considering multiple routes.

for i in range(1, n+1):
    d[i][i] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

for i in range(1, n+1):
    for j in range(1, n+1):
        if d[i][j] == INF:
            print(0, end=" ")
        else:
            print(d[i][j], end=" ")
    print()
