from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.mat = []
        self.visited = []
        self.M = 0
        self.N = 0

    def init_visited(self):
        self.visited = [[100000 for _ in range(self.N)] for _ in range(self.M)]

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        self.mat = mat
        self.M = len(mat)
        self.N = len(mat[0])
        self.init_visited()
        q = deque()
        for i in range(self.M):
            for j in range(self.N):
                if self.mat[i][j] == 0:
                    q.append((i, j, 0))
        while q:
            cr, cc, cs = q.popleft()
            if self.visited[cr][cc] < cs:
                continue
            self.visited[cr][cc] = min(cs, self.visited[cr][cc])
            for d in range(4):
                nr, nc = cr + dr[d], cc + dc[d]
                if -1 < nr < self.M and -1 < nc < self.N:
                    if self.mat[nr][nc]:
                        q.append((nr, nc, cs+1))
        return self.visited


