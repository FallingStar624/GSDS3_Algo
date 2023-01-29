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
        q = deque()
        q.append((row, col))
        while q:
            r, c = q.popleft()
            self.grid[r][c] = 1
            for d in range(4):
                nr, nc = r + dr[d], c + dc[d]
                if -1 < nr < rows and -1 < nc < cols:
                    if not self.grid[nr][nc] and not self.visited[nr][nc]:
                        self.visited[nr][nc] = True
                        q.append((nr, nc))

    def closedIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        rows = len(grid)
        cols = len(grid[0])
        self.visited = [[0 for _ in range(cols)] for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
                    if not self.grid[i][j] and not self.visited[i][j]:
                        self.bfs(i, j)

        for i in range(rows):
            for j in range(cols):
                if not self.grid[i][j] and not self.visited[i][j]:
                    print(i, j)
                    self.bfs(i, j)
                    self.ans += 1
        return self.ans



