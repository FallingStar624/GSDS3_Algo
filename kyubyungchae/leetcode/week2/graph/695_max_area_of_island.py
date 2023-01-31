from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        self.M = len(grid)
        self.N = len(grid[0])
        self.visited = [[0 for _ in range(self.N)] for _ in range(self.M)]

        max_area = 0
        for i in range(self.M):
            for j in range(self.N):
                if self.visited[i][j] == 0 and grid[i][j] == 1:
                    area = self.__dfs(grid, i, j)
                    if area > max_area:
                        max_area = area

        return max_area

    def __dfs(self, grid, i, j) -> int:
        area = 0

        if (i < self.M and i >= 0) and (j < self.N and j >= 0) and self.visited[i][j] == 0 and grid[i][j] == 1:
            self.visited[i][j] = 1
            area = 1
            area += self.__dfs(grid, i+1, j)
            area += self.__dfs(grid, i-1, j)
            area += self.__dfs(grid, i, j-1)
            area += self.__dfs(grid, i, j+1)

        return area
    


if __name__ == '__main__':
    sol = Solution()

    grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]] 
    # grid = [[1,1,0,0,0],
    #         [1,1,0,0,0],
    #         [0,0,0,1,1],
    #         [0,0,0,1,1]]
    sl = sol.maxAreaOfIsland(grid)

    print(sl)