
from typing import List
from collections import deque


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        dr = [1, -1, 0, 0, 1, 1, -1, -1]
        dc = [0, 0, -1, 1, 1, -1, 1, -1]
        n = len(grid)
        if grid[0][0] | grid[n-1][n-1]:
            return -1
        r, c = 0, 0
        grid[r][c] = 1
        q = deque([(r, c)])
        while q:
            cr, cc = q.popleft()
            curr_step = grid[cr][cc]
            for d in range(8):
                nr, nc = cr + dr[d], cc + dc[d]
                if -1 < nr < n and -1 < nc < n:
                    if grid[nr][nc] == 0:
                        q.append((nr, nc))
                        grid[nr][nc] = curr_step+1
        ans = grid[n-1][n-1]
        if ans == 0:
            ans = -1
        return ans



