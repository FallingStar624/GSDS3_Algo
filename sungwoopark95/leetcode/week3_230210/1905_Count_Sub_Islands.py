from typing import List

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        self.grid1 = grid1

        subIslands = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1 and visited[i][j] == 0:
                    self.result = []
                    self.dfs(grid2, visited, m, n, i, j)
                    if False in self.result: continue
                    subIslands += 1
        return subIslands

    def dfs(self, grid, visited, m, n, curX, curY):
        if (0<=curX<m) and (0<=curY<n) and grid[curX][curY] == 1 and visited[curX][curY] == 0:
            visited[curX][curY] = 1
            self.result.append((self.grid1[curX][curY] == 1))
            self.dfs(grid, visited, m, n, curX-1, curY)
            self.dfs(grid, visited, m, n, curX+1, curY)
            self.dfs(grid, visited, m, n, curX, curY-1)
            self.dfs(grid, visited, m, n, curX, curY+1)
