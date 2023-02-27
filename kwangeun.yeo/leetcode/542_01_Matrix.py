class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n_rows = len(mat)
        n_cols = len(mat[0])
        v = [[-1] * n_cols for _ in range(n_rows)]
        q = deque([])
        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]
        for r in range(n_rows):
            for c in range(n_cols):
                if mat[r][c] == 0:
                    v[r][c] = 0
                    q.append((r, c))
        while q:
            r, c = q.popleft()
            d = v[r][c]
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= n_rows or nc >= n_cols:
                    continue
                if v[nr][nc] == -1 and mat[nr][nc] == 1:
                    v[nr][nc] = d + 1
                    q.append((nr, nc))
        return v