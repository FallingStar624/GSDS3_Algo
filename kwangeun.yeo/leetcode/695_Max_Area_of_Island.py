from collections import deque
 
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.nrow = len(grid)
        self.ncol = len(grid[0])
        self.visit = [[0] * self.ncol for _ in range(self.nrow)]

        max_area = 0
        for r in range(self.nrow):
            for c in range(self.ncol):
                if self.grid[r][c] == 1 and self.visit[r][c] == 0:
                    max_area = max(max_area, self.bfs(r, c))
        return max_area
    
    def bfs(self, sr, sc):
        area = 1
        q = deque([(sr, sc)])
        self.visit[sr][sc] = 1
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            r, c = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= self.nrow or nc >= self.ncol:
                    continue
                if self.visit[nr][nc] == 1 or self.grid[nr][nc] != 1:
                    continue
                self.visit[nr][nc] = 1
                q.append((nr, nc))
                area += 1
        return area