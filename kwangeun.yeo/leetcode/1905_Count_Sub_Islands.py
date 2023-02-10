from collections import deque


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.grid_lookup = grid1
        self.grid = grid2
        self.n_rows = len(self.grid)
        self.n_cols = len(self.grid[0])
        self.visit = [[0] * self.n_cols for _ in range(self.n_rows)]
        
        subisland = 0
        for r in range(self.n_rows):
            for c in range(self.n_cols):
                if self.visit[r][c] == 0 and self.grid[r][c] == 1:
                    subisland += self.bfs(r, c)
        return subisland
    
    def bfs(self, sr, sc):
        q = deque([])
        dr = [1, 0, -1, 0]
        dc = [0, 1, 0, -1]

        self.visit[sr][sc] = 1
        q.append((sr, sc))

        subisland = self.grid_lookup[sr][sc]
        while q:
            cr, cc = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = cr + mr
                nc = cc + mc
                if nr < 0 or nc < 0 or nr >= self.n_rows or nc >= self.n_cols:
                    continue
                if self.visit[nr][nc] == 1 or self.grid[nr][nc] == 0:
                    continue
                self.visit[nr][nc] = 1
                q.append((nr, nc))
                if self.grid_lookup[nr][nc] == 0:
                    subisland = 0
        return subisland