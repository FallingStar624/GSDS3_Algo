from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.grid = []
        self.visited = []
        self.ans = 0

    def bfs(self, row, col):
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        rows = len(self.grid)
        cols = len(self.grid[0])
        self.visited[row][col] = True
        area = 1
        q = deque()
        q.append((row, col))
        while q:
            r, c = q.popleft()
            for d in range(4):
                nr, nc = r + dr[d], c + dc[d]
                if -1 < nr < rows and -1 < nc < cols:
                    if self.grid[nr][nc] and not self.visited[nr][nc]:
                        self.visited[nr][nc] = True
                        area += 1
                        q.append((nr, nc))
        self.ans = max(self.ans, area)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        rows = len(grid)
        cols = len(grid[0])
        self.visited = [[0 for _ in range(cols)] for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if self.grid[i][j] and not self.visited[i][j]:
                    self.bfs(i, j)
                else:
                    self.visited[i][j] = True
        return self.ans

