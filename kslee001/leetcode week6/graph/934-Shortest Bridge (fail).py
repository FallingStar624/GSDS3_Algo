def DFS(y, x, color):
    s = []
    s.append((y, x))
    islands.append((y, x, color))
    while s:
        cy, cx = s.pop()
        G[cy][cx] = color
        V[cy][cx] = 1
        for d in range(4):
            ny, nx = cy+dy[d], cx+dx[d]
            if oob(n, ny, nx):
                continue
            elif V[ny][nx] == 1:
                continue
            elif G[ny][nx] == 0:
                V[ny][nx] = 1
                continue
            s.append((ny, nx))
            islands.append((ny, nx, color))

            
def BFS(islands):
    q = islands
    while q:
        y, x, cur_color = q.pop(0)
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            if oob(n, ny, nx):
                continue
            elif V[ny][nx] == V[y][x]:
                continue
            elif (G[ny][nx] == 0)|(G[ny][nx] == cur_color):
                V[ny][nx] = V[y][x] + 1
                q.append((ny, nx, color))
                continue
            return cur_v+1
    return False
            
    
grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
G = grid
n = len(G)

V = [[-1 for _ in range(X)] for __ in range(Y)]
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
oob = lambda n,y,x : (y<0)|(y>=n)|(x<0)|(x>=n)

islands = []

color = 1
for y in range(n):
    for x in range(n):    
        if V[y][x]==1 :
            continue
        if G[y][x]==0 :
            V[y][x] =1
            continue
            
        # DFS
        DFS(y, x, color)
        color += 1

G, V
