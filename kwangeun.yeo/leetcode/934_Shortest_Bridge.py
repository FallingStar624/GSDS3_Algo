class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.n = len(grid)
        self.dr = [1, 0, -1, 0]
        self.dc = [0, 1, 0, -1]
        q, v = self.bfs1()
        return self.bfs2(q, v)
    
    def bfs1(self):
        q1 = deque([])
        q2 = deque([])
        v = [[-1] * self.n for _ in range(self.n)]
        for r in range(self.n):
            for c in range(self.n):
                if self.grid[r][c] == 1:
                    q1.append((r, c))
                    q2.append((r, c))
                    v[r][c] = 0
                    while q1:
                        r, c = q1.popleft()
                        for mr, mc in zip(self.dr, self.dc):
                            nr = r + mr
                            nc = c + mc
                            if nr < 0 or nc < 0 or nr >= self.n or nc >= self.n:
                                continue
                            if self.grid[nr][nc] == 1 and v[nr][nc] == -1:
                                q1.append((nr, nc))
                                q2.append((nr, nc))
                                v[nr][nc] = 0
                    return (q2, v)
        
    def bfs2(self, q, v):
        while q:
            r, c = q.popleft()
            for mr, mc in zip(self.dr, self.dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= self.n or nc >= self.n:
                    continue
                if v[nr][nc] != -1:
                    continue
                if self.grid[nr][nc] == 1:
                    return v[r][c]
                else:
                    q.append((nr, nc))
                    v[nr][nc] = v[r][c] + 1