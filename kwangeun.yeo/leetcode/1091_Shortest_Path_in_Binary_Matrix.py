class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1
        n = len(grid)
        v = [[0] * n for _ in range(n)]
        dr = [1, 0, -1, 0, -1, -1, 1, 1]
        dc = [0, 1, 0, -1, -1, 1, -1, 1]
        q = deque([(0, 0)])
        v[0][0] = 1
        while q:
            r, c = q.popleft()
            d = v[r][c]
            if r == n - 1 and c == n - 1:
                return d
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= n or nc >= n:
                    continue
                if v[nr][nc] == 0 and grid[nr][nc] == 0:
                    q.append((nr, nc))
                    v[nr][nc] = d + 1
        return -1