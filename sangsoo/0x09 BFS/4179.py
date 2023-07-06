import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline()) for _ in range(n)]

fvis = [[0 for _ in range(m)] for _ in range(n)]
jvis = [[0 for _ in range(m)] for _ in range(n)]
ftime = [[0 for _ in range(m)] for _ in range(n)]
jtime = [[0 for _ in range(m)] for _ in range(n)]
num, mx = 0, 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

fq = deque()
jq = deque()

# fire
for i in range(n):
    for j in range(m):
        if board[i][j] == 'F':
            fq.append((i, j))
            ftime[i][j] = 0
            fvis[i][j] = 1
        else:
            ftime[i][j] = -1
            fvis[i][j] = 0
while (fq):
    curx, cury = fq.popleft()
    for i in range(4):
        nx = curx + dx[i]
        ny = cury + dy[i]
        if (nx < 0 or nx >=n or ny < 0 or ny >=m): continue
        if (fvis[nx][ny] or board[nx][ny] == '#'): continue
        fvis[nx][ny] = 1
        ftime[nx][ny] = ftime[curx][cury] + 1
        fq.append((nx, ny))

# J
for i in range(n):
    for j in range(m):
        if board[i][j] == 'J':
            jq.append((i,j))
            jtime[i][j] = 0
            jvis[i][j] = 1
        else:
            jtime[i][j] = -1
            jvis[i][j] = 0

flag = False
while (jq):
    curx, cury = jq.popleft()
    if curx == 0 or  curx == n-1 or cury == 0 or cury == m-1:
        print(jtime[curx][cury]+1)
        flag = True
        break
    for i in range(4):
        nx = curx + dx[i]
        ny = cury + dy[i]

        if nx<0 or nx>=n or ny<0 or ny>=m: continue
        if jvis[nx][ny] or board[nx][ny]=='#': continue
        if ftime[nx][ny] != -1 and jtime[curx][cury]+1>=ftime[nx][ny]: continue
        # 불이 번졌는데, J가 늦게 갔으면 continue
        # 불이 아예 안번졌으면 ... J는 계속 진행
        jvis[nx][ny] = 1
        jtime[nx][ny] = jtime[curx][cury]+1

        jq.append((nx, ny))


if flag == False:
    print("IMPOSSIBLE")