from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        max_area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and visited[i][j] == 0:
                    self.area = 0
                    self.dfs(grid, visited, m, n, i, j)
                    if max_area < self.area:
                        max_area = self.area
        
        return max_area


    def dfs(self, grid, visited, m, n, curX, curY):
        if (0<=curX<m) and (0<=curY<n) and visited[curX][curY] == 0 and grid[curX][curY] == 1:
            visited[curX][curY] = 1
            self.area += 1
            self.dfs(grid, visited, m, n, curX-1, curY)
            self.dfs(grid, visited, m, n, curX+1, curY)
            self.dfs(grid, visited, m, n, curX, curY+1)
            self.dfs(grid, visited, m, n, curX, curY-1)
