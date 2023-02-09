from typing import List

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        self.closed = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and visited[i][j] == 0:
                    if self.dfs(grid, visited, m, n, i, j):
                        self.closed += 1
        return self.closed

    
    def dfs(self, grid, visited, m, n, curX, curY):
        if (0<=curX<m) and (0<=curY<n) and grid[curX][curY] == 0 and visited[curX][curY] == 0:
            visited[curX][curY] = 1
            result1 = self.dfs(grid, visited, m, n, curX-1, curY)
            result2 = self.dfs(grid, visited, m, n, curX+1, curY)
            result3 = self.dfs(grid, visited, m, n, curX, curY-1)
            result4 = self.dfs(grid, visited, m, n, curX, curY+1)
            result = [result1, result2, result3, result4]
            if False in result:
                return False
            return True
        elif (curX<0) or (curX>=m) or (curY<0) or (curY>=n):
            return False
        elif grid[curX][curY] == 1:
            return True
