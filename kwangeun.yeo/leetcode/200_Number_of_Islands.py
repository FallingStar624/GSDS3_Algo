class Solution:
    def numIslands(self, grid) -> int:
        self.grid = grid
        self.n_row = len(grid)
        self.n_col = len(grid[0])
        self.visit = [[0] * self.n_col for _ in range(self.n_row)]
        island = 0
        for i in range(self.n_row):
            for j in range(self.n_col):
                if self.grid[i][j] == '1' and not self.visit[i][j]:
                    self.bfs(i, j)
                    island += 1
        return island
    
    def bfs(self, sr, sc):
        q = []
        dr = [1, 0, -1, 0]
        dc = [0, 1, 0, -1]
        self.visit[sr][sc] = 1
        q.append([sr, sc])
        while q:
            cr, cc = q.pop()
            for mr, mc in zip(dr, dc):
                nr = cr + mr
                nc = cc + mc
                if nr < 0 or nr >= self.n_row or nc < 0 or nc >= self.n_col:
                    continue
                if self.grid[nr][nc] != '1':
                    continue
                if self.visit[nr][nc]:
                    continue
                self.visit[nr][nc] = 1
                q.append([nr, nc])