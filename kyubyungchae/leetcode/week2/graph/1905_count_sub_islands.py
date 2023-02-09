from typing import List


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        
        self.M = len(grid1)
        self.N = len(grid1[0])

        self.visited1 = [[0 for _ in range(self.N)] for _ in range(self.M)]
        self.visited2 = [[0 for _ in range(self.N)] for _ in range(self.M)]

        counter = 0
        for i in range(self.M):
            for j in range(self.N):
                if grid1[i][j] == 1 and grid2[i][j] == 1 and self.visited2[i][j] == 0:
                    self.__dfs(grid1, grid2, i, j)
                    counter += 1
        return counter


    def __dfs(self, grid1, grid2, i, j) -> int:

        if (i < self.M and i >= 0) and (j < self.N and j >= 0) and self.visited2[i][j] == 0 and grid2[i][j] == 1: 
            self.visited2[i][j] = 1
            self.__dfs(grid1, grid2, i+1, j)
            self.__dfs(grid1, grid2, i-1, j)
            self.__dfs(grid1, grid2, i, j-1)
            self.__dfs(grid1, grid2, i, j+1)


if __name__ == '__main__':
    sol = Solution()

    grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]
    grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
    sl = sol.countSubIslands(grid1, grid2)

    print(sl)