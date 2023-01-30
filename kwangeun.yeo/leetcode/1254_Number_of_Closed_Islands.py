from collections import deque

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.nrow = len(grid)
        self.ncol = len(grid[0])
        self.visit = [[0] * self.ncol for _ in range(self.nrow)]

        island = 0
        for r in range(self.nrow):
            for c in range(self.ncol):
                if self.grid[r][c] == 0 and self.visit[r][c] == 0:
                    island += self.bfs(r, c)
        return island
    
    def bfs(self, sr, sc):
        q = deque([(sr, sc)])
        self.visit[sr][sc] = 1
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]
        ret = 1

        while q:
            r, c = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= self.nrow or nc >= self.ncol:
                    ret = 0
                    continue
                if self.visit[nr][nc] == 1 or self.grid[nr][nc] != 0:
                    continue
                self.visit[nr][nc] = 1
                q.append((nr, nc))

        return ret