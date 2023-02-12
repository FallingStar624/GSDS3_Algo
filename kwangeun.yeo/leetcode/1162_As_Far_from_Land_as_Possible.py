from collections import deque


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        q = deque([])
        n = len(grid)
        v = [[-1] * n for _ in range(n)]
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]
        
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    q.append((r, c, 0))
        while q:
            r, c, d = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                nd = d + 1
                if nr < 0 or nc < 0 or nr >= n or nc >= n:
                    continue
                if v[nr][nc] == -1 and grid[nr][nc] == 0:
                    q.append((nr, nc, nd))
                    v[nr][nc] = nd
        return max([max(row) for row in v])