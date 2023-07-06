import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
vis = [[0 for _ in range(m)] for _ in range(n)]
num, mx = 0, 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(n):
    for j in range(m):
        if board[i][j] == 0 or vis[i][j]: continue
        num += 1
        dq = deque()
        vis[i][j] = 1
        dq.append((i, j))
        area = 0
        while dq:
            area += 1
            curx, cury = dq.popleft()
            for dir in range(4):
                nx = curx + dx[dir]
                ny = cury + dy[dir]
                if (nx<0 or nx>=n or ny<0 or ny>=m): continue
                if (vis[nx][ny] or board[nx][ny] != 1): continue
                vis[nx][ny] = 1
                dq.append((nx, ny))
        mx = max(area, mx)
print(num)
print(mx)