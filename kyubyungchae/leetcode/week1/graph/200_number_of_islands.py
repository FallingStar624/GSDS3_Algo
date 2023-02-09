from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.M = len(grid)
        self.N = len(grid[0])

        self.visited = [[0 for _ in range(self.N)] for _ in range(self.M)]
        self.grid = grid

        num = 0
        for i in range(self.M):
            for j in range(self.N):
                if self.visited[i][j] == 0 and self.grid[i][j] == "1":
                    self.dfs(i, j)
                    num += 1

        return num

    def dfs(self, i, j):
        
        if (i < self.M and i >= 0) and (j < self.N and j >= 0) and self.visited[i][j] == 0 and self.grid[i][j] == "1":
            self.visited[i][j] = 1
            self.dfs(i+1, j)
            self.dfs(i-1, j)
            self.dfs(i, j-1)            
            self.dfs(i, j+1)


if __name__ == '__main__':

    sol = Solution()
    grid = [["1","0","1","1","0","1","1"]]

    sl = sol.numIslands(grid)
    print(sl)