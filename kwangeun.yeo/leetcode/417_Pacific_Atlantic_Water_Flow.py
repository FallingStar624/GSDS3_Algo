from collections import deque


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.heights = heights
        self.n_rows = len(heights)
        self.n_cols = len(heights[0])

        pac_q = [(0, c) for c in range(self.n_cols)] + [(r, 0) for r in range(self.n_rows)]
        atl_q = [(self.n_rows - 1, c) for c in range(self.n_cols)] + [(r, self.n_cols - 1) for r in range(self.n_rows)]
        pac_v = self.bfs(deque(pac_q))
        atl_v = self.bfs(deque(atl_q))
        return [[r, c] for r in range(self.n_rows) for c in range(self.n_cols) if pac_v[r][c] and atl_v[r][c]]
    
    def bfs(self, q):
        v = [[0] * self.n_cols for _ in range(self.n_rows)]
        dr = [1, 0, -1, 0]
        dc = [0, 1, 0, -1]
        for r, c in q:
            v[r][c] = 1
        while q:
            r, c = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= self.n_rows or nc >= self.n_cols:
                    continue
                if v[nr][nc] == 0 and self.heights[nr][nc] >= self.heights[r][c]:
                    q.append((nr, nc))
                    v[nr][nc] = 1
        return v