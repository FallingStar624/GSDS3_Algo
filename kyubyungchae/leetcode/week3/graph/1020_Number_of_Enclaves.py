from typing import List

class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])

        def dfs(i, j):
            grid[i][j] = 0
            for x, y in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if (0 <= x < m) and (0 <= y < n) and grid[x][y] == 1:
                    dfs(x, y)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (i == 0 or j == 0 or i == m-1 or j == n-1):
                    dfs(i, j)
        
        return sum(sum(row) for row in grid)


    


if __name__ == '__main__':
    sol = Solution()
    grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    sl = sol.numEnclaves(grid)

    print(sl)