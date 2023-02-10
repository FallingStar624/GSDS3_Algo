from collections import deque


class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.n_rows = len(grid)
        self.n_cols = len(grid[0])
        self.visit = [[0] * self.n_cols for _ in range(self.n_rows)]
        for r in [0, self.n_rows - 1]:
            for c in range(self.n_cols):
                if self.visit[r][c] == 0 and self.grid[r][c] == 1:
                    self.bfs(r, c)
        for c in [0, self.n_cols - 1]:
            for r in range(self.n_rows):
                if self.visit[r][c] == 0 and self.grid[r][c] == 1:
                    self.bfs(r, c)
        area = 0
        for r in range(self.n_rows):
            for c in range(self.n_cols):
                if self.visit[r][c] == 0 and self.grid[r][c] == 1:
                    area += self.bfs(r, c)
        return area
    
    def bfs(self, sr, sc):
        q = deque([])
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]
        
        self.visit[sr][sc] = 1
        q.append((sr, sc))
        area = 1
        while q:
            cr, cc = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = cr + mr
                nc = cc + mc
                if nr < 0 or nc < 0 or nr >= self.n_rows or nc >= self.n_cols:
                    continue
                if self.visit[nr][nc] != 0 or self.grid[nr][nc] == 0:
                    continue
                self.visit[nr][nc] = 1
                q.append((nr, nc))
                area += 1
        return area