        n = len(grid)
        if (grid[0][0])|(grid[n-1][n-1]):
            return -1

        Y = len(grid)
        X = len(grid[0])

        G = grid
        V = [[0 for _ in range(X)] for _ in range(Y)]
        
        #  [동, 상동, 상, 상좌,  좌, 하좌, 하, 하동]
        dy = [0,   1,  1,    1,   0,  -1,  -1, -1]
        dx = [1,   1,  0,   -1,  -1,  -1,   0,  1]
        
        length = 0
        queue = []
        queue.append((0, 0))
        V[0][0] = 1
        while queue:
            y, x = queue.pop(0)

            for d in range(8):
                ny, nx = y+dy[d], x+dx[d]
                # oob
                if (ny<0)|(ny>=Y)|(nx<0)|(nx>=X):
                    continue
                # visit
                if V[ny][nx] != 0:
                    continue
                # wall
                if G[ny][nx] == 1:
                    continue
                V[ny][nx] = V[y][x] + 1
                queue.append((ny,nx))
        if V[n-1][n-1] == 0:
            return -1
        return V[Y-1][X-1]