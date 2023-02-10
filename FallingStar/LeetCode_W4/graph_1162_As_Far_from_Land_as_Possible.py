class Solution:
    def __init__(self):
        self.grid = []
        self.rows = 0
        self.cols = 0
        self.visited = []
        self.ans = -1

    def dfs(self, r, c, step):
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        for d in range(4):
            nr, nc = r + dr[d], c + dc[d]
            if -1 < nr < self.rows and -1 < nc < self.cols\
                and self.grid[nr][nc] == 0\
                    and self.visited[nr][nc] > step:
                self.visited[nr][nc] = step
                self.dfs(nr, nc, step+1)

    def maxDistance(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.visited = [[200 for _ in range(self.cols)] for _ in range(self.rows)]
        for i in range(self.rows):
            for j in range(self.cols):
                if self.grid[i][j] == 1:
                    self.dfs(i, j, 1)
        for i in range(self.rows):
            for j in range(self.cols):
                if self.grid[i][j] == 0:
                    self.ans = max(self.ans, self.visited[i][j])
        if self.ans == 200:
            self.ans = -1
        return self.ans



