class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        v = [[0] * n for _ in range(m)]
        q = deque([(0, 0)])
        v[0][0] = 1
        while q:
            r, c = q.popleft()
            if r == m - 1 and c == n - 1:
                return v[r][c]
            for nr, nc in [(r + 1, c), (r, c + 1)]:                
                if nr < 0 or nc < 0 or nr >= m or nc >= n:
                    continue
                if v[nr][nc] > 0:
                    continue
                u1 = v[nr - 1][nc] if nr > 0 else 0
                u2 = v[nr][nc - 1] if nc > 0 else 0
                v[nr][nc] = u1 + u2
                q.append((nr, nc))
        return -1