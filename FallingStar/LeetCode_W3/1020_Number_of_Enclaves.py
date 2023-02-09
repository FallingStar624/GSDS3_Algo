from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.rows = 0
        self.cols = 0
        self.grid = []
        self.visited = []
        self.ans = 0

    def bfs(self, row, col):
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        area = 0
        isolate = True
        q = deque([(row, col)])
        self.visited[row][col] = True
        while q:
            cr, cc = q.pop()
            area += 1
            if cr==0 or cr==self.rows-1 or cc==0 or cc==self.cols-1:
                isolate = False
            for d in range(4):
                nr, nc = cr+dr[d], cc+dc[d]
                if -1<nr<self.rows and -1<nc<self.cols:
                    if self.grid[nr][nc] and not self.visited[nr][nc]:
                        self.visited[nr][nc] = True
                        q.append((nr, nc))
        if isolate:
            self.ans += area

    def numEnclaves(self, grid: List[List[int]]) -> int:
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.grid = grid
        self.visited = [[False for _ in range(self.cols)] for _ in range(self.rows)]
        for i in range(self.rows):
            for j in range(self.cols):
                if self.grid[i][j] == 1 and not self.visited[i][j]:
                    self.bfs(i, j)
                else:
                    self.visited[i][j] = True
        return self.ans
