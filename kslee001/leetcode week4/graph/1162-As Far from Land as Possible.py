class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]

        Y = len(grid)
        X = len(grid[0])
        check_sum = sum([sum(g) for g in grid])
        if check_sum == 0:
            return -1
        if check_sum == X*Y:
            return -1


        G = grid
        V = [[-1 for _ in range(X)] for _ in range(Y)]
        result = [[300 for _ in range(X)] for _ in range(Y)]

        queue = []
        for y in range(Y):
            for x in range(X):
                if G[y][x] == 1:
                    queue.append((y,x))
                    V[y][x] = 0
                    result[y][x] = 0
                    
        while queue:
            cy, cx = queue.pop(0)
            for d in range(4):
                ny, nx = cy+dy[d], cx+dx[d]

                if ( 0 <= ny < Y ) & ( 0 <= nx < X ):
                    if V[ny][nx] != -1:
                        continue
                    if G[ny][nx] == 0:
                        V[ny][nx] = V[cy][cx] + 1
                    else:
                        V[ny][nx] = 0
                    result[ny][nx] = min(result[ny][nx], V[ny][nx])
                    queue.append((ny,nx))

        for r in result:
            print(r)
        mv = -1
        for y in range(Y):
            for x in range(X):
                if result[y][x] > mv:
                    mv = result[y][x]
        return mv