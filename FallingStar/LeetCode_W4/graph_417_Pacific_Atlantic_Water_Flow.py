from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.heights = []
        self.visited = []
        self.pacific = []
        self.atlantic = []
        self.M = 0
        self.N = 0
        self.ans = []

    def init_visited(self):
        self.visited = [[False for _ in range(self.N)] for _ in range(self.M)]

    def bfs(self, r, c, pacific=True):
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        q = deque([(r, c)])
        self.visited[r][c] = True
        while q:
            cr, cc = q.popleft()
            if pacific:
                self.pacific[cr][cc] = 1
            else:
                self.atlantic[cr][cc] = 1
            for d in range(4):
                nr, nc = cr + dr[d], cc + dc[d]
                if -1 < nr < self.M and -1 < nc < self.N:
                    if self.heights[nr][nc] >= self.heights[cr][cc]:
                        if not self.visited[nr][nc]:
                            self.visited[nr][nc] = True
                            q.append((nr, nc))

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.heights = heights
        self.M = len(heights)
        self.N = len(heights[0])
        self.pacific = [[0 for _ in range(self.N)] for _ in range(self.M)]
        self.atlantic = [[0 for _ in range(self.N)] for _ in range(self.M)]

        for i in range(self.M):
            self.init_visited()
            self.bfs(i, 0)
        for j in range(self.N):
            self.init_visited()
            self.bfs(0, j)
        for i in range(self.M):
            self.init_visited()
            self.bfs(i, self.N-1, False)
        for j in range(self.N):
            self.init_visited()
            self.bfs(self.M-1, j, False)

        for i in range(self.M):
            for j in range(self.N):
                if self.pacific[i][j] == 1 and self.atlantic[i][j] == 1:
                    self.ans.append([i, j])

        return self.ans

