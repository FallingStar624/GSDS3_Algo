from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.grid1 = []
        self.grid2 = []
        self.visited = []
        self.rows = 0
        self.cols = 0
        self.ans = 0

    def bfs(self, row, col):
        sub = True
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        q = deque([(row, col)])
        self.visited[row][col] = True
        while q:
            cr, cc = q.popleft()
            if self.grid2[cr][cc] and not self.grid1[cr][cc]:
                sub = False
            for d in range(4):
                nr, nc = cr+dr[d], cc+dc[d]
                if -1 < nr < self.rows and -1 < nc < self.cols:
                    if self.grid2[nr][nc] and not self.visited[nr][nc]:
                        q.append((nr, nc))
                        self.visited[nr][nc] = True
        if sub:
            self.ans += 1

    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.grid1 = grid1
        self.grid2 = grid2
        self.rows = len(grid1)
        self.cols = len(grid1[0])
        self.visited = [[False for _ in range(self.cols)] for _ in range(self.rows)]
        for i in range(self.rows):
            for j in range(self.cols):
                if self.grid1[i][j] and self.grid2[i][j] and not self.visited[i][j]:
                    self.bfs(i, j)
        return self.ans

