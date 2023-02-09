from typing import Optional, List
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # DXDY
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]

        # grid boundaries
        Y = len(grid)
        X = len(grid[0])

        # boards
        V = [[False for _ in range(X)] for _ in range(Y)]
        G = grid

        # Out of bounds
        def OOB(x, limit):
            return (x<0) | (x>=limit)

        # Queue
        queue = list()
        max_area = 0

        # sliding search
        for y in range(Y):
            for x in range(X):
                # visit check
                if V[y][x]:
                    continue
                if G[y][x] == 0:
                    continue

                # BFS  (when G[y][x] == 1 and V[y][x]!= True)
                queue.append( (y,x) )
                cur_area = 0 # new island's area
                while (queue):
                    cur_y, cur_x = queue.pop(0) # FIFO
                    if V[cur_y][cur_x] : continue
                    V[cur_y][cur_x] = True  # visit
                    cur_area += 1  # add area
                    print(cur_y, cur_x)

                    for d in range(4):
                        new_y = cur_y + dy[d]
                        new_x = cur_x + dx[d]

                        # OOB check
                        if OOB(new_y, Y) | OOB(new_x, X): continue
                        # visit check
                        if V[new_y][new_x]: continue
                        # land check
                        if G[new_y][new_x] == 0: continue

                        queue.append((new_y, new_x))

                if cur_area > max_area:
                    max_area = cur_area

        return max_area
