from collections import deque

class Solution:
    def __init__(self):
        self.ans = 201
        self.N = 0
        self.starts = []
        self.grid = []

    def differ(self, r, c):
        dr = [0, 0, -1, 1]
        dc = [1, -1, 0, 0]
        self.grid[r][c] = 2
        for d in range(4):
            nr, nc = r + dr[d], c + dc[d]
            if -1 < nr < self.N and -1 < nc < self.N:
                if self.grid[nr][nc] == 1:
                    self.starts.append((nr, nc))
                    self.grid[nr][nc] = 2
                    self.differ(nr, nc)

    def get_minimum(self):
        dr = [0, 0, -1, 1]
        dc = [1, -1, 0, 0]
        for i, j in self.starts:
            self.visited[i][j] = True
        q = deque(self.starts)
        while q:
            cr, cc = q.popleft()
            for d in range(4):
                nr, nc = cr + dr[d], cc + dc[d]
                if -1 < nr < self.N and -1 < nc < self.N:
                    if self.grid[nr][nc] == 1:
                        self.ans = min(self.ans, self.grid[cr][cc])
                    elif self.grid[nr][nc] == 0 and (nr, nc) not in q:
                        self.grid[nr][nc] = self.grid[cr][cc] + 1
                        q.append((nr, nc))
                    elif self.grid[nr][nc] > self.grid[cr][cc]:
                        self.grid[nr][nc] = self.grid[cr][cc] + 1
                        if (nr, nc) not in q:
                            q.append((nr, nc))


    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.N = len(grid)
        self.visited = [[0 for _ in range(self.N)] for _ in range(self.N)]
        self.grid = grid
        for n in range(self.N*self.N):
                i, j = n // self.N, n % self.N
                if self.grid[i][j] == 1:
                    self.starts.append((i, j))
                    self.grid[i][j] = 2
                    self.differ(i, j)
                    break
        self.get_minimum()
        print(self.grid)
        return self.ans-2

