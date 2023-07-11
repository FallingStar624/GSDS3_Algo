import sys
from collections import deque
T = int(input())
dx =[1, 0, -1, 0]
dy =[0, 1, 0, -1]
while(T):
    board = [[0 for _ in range(52)] for _ in range(52)]
    vis = [[0 for _ in range(52)] for _ in range(52)]
    M, N, K = map(int, sys.stdin.readline().split())
    for i in range(K):
        x, y = map(int, sys.stdin.readline().split())
        board[x][y] = 1
    cnt = 0
    for i in range(M):
        for j in range(N):
            if(board[i][j] == 0 or vis[i][j]): continue
            cnt += 1
            q = deque([])
            q.append((i, j)); vis[i][j] = 1
            while(q):
                curX, curY = q.popleft()
                for dir in range(4):
                    nx = curX + dx[dir]
                    ny = curY + dy[dir]
                    if(nx < 0 or nx > M or ny < 0 or ny > N): continue
                    if(vis[nx][ny] or board[nx][ny] != 1): continue
                    vis[nx][ny] = 1
                    q.append((nx, ny))
    print(cnt)
    T -= 1