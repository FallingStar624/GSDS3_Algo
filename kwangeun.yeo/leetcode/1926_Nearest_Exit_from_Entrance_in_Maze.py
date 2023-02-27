class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        n_rows = len(maze)
        n_cols = len(maze[0])
        q = deque([])
        v = [[-1] * n_cols for _ in range(n_rows)]
        dr = [1, 0, -1, 0]
        dc = [0, 1, 0, -1]

        er, ec = entrance
        q.append((er, ec))
        v[er][ec] = 0
        while q:
            r, c = q.popleft()
            for mr, mc in zip(dr, dc):
                nr = r + mr
                nc = c + mc
                if nr < 0 or nc < 0 or nr >= n_rows or nc >= n_cols:
                    if r == er and c == ec:
                        continue
                    return v[r][c]
                if v[nr][nc] == -1 and maze[nr][nc] == '.':
                    v[nr][nc] = v[r][c] + 1
                    q.append((nr, nc))
        return -1