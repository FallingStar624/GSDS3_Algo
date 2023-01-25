class Solution:
    def numIslands(self, grid: List[List[str]]):
        def OOB(cur, limit):
            if (cur<0) | (cur>=limit):
                return True
            else:
                return False
        from collections import deque
        H = len(grid)
        W = len(grid[0])
        V = [[False for _ in range(W)] for _ in range(H)]
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]
        num_islands = 0

        for y in range(H):
            for x in range(W):
                # visit check
                if V[y][x] == True:
                    continue

                # Case 'ocean'
                if grid[y][x] == '0':
                    V[y][x] = True
                    continue

                # Case 'land' -> start exploration
                num_islands +=1
                stack =  deque()
                stack.append((y, x))
                while (stack):
                    cur = stack.pop() # pop front                    
                    cury, curx = cur

                    # visit
                    V[cury][curx] = True

                    # looking around
                    for idx in range(4):
                        ny = cury+dy[idx]
                        nx = curx+dx[idx]

                        # oob check
                        if OOB(ny, H) | OOB(nx, W) :
                            continue
                        # visit check
                        if V[ny][nx] == True:
                            continue
                        # land check
                        if grid[ny][nx] == '0':
                            continue
                        stack.append((ny, nx))
        return num_islands