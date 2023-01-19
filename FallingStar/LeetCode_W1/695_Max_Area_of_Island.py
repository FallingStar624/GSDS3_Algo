from typing import List
from collections import deque

class Solution:
    def __init__(self):
        self.visited = []

    def init_visited(self, rows: int, cols: int) -> None:
        self.visited = [[False for _ in range(cols)] for _ in range(rows)]

    def BFT(self, grid: List[List[str]], sr: int, sc: int, rows: int, cols: int) -> None:
        dr = [1, -1, 0, 0]
        dc = [0, 0, -1, 1]
        q = deque([(sr, sc)])
        while q:
            cr, cc = q.popleft()
            self.visited[cr][cc] = True
            for d in range(4):
                nr, nc = cr+dr[d], cc+dc[d]
                if -1 < nr < rows and -1 < nc < cols:
                    if not self.visited[nr][nc] and grid[nr][nc] == "1" and not (nr, nc) in q:
                        q.append((nr, nc))

    def numIslands(self, grid: List[List[str]]) -> int:
        answer = 0
        rows = len(grid)
        cols = len(grid[0])
        self.init_visited(rows, cols)
        for i in range(rows):
            for j in range(cols):
                if self.visited[i][j]:
                    continue
                if grid[i][j] == "0":
                    continue
                if not self.visited[i][j] and grid[i][j] == "1":
                    print(i, j)
                    answer += 1
                    self.BFT(grid, i, j, rows, cols)
        return answer

