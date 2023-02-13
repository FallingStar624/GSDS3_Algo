from typing import List


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m = len(grid2)
        n = len(grid2[0])

        def dfs(i: int, j: int) -> int:
            if i < 0 or i == m or j < 0 or j == n:
                return 1
            if grid2[i][j] != 1:
                return 1

            grid2[i][j] = 2  # Mark 2 as visited

            return dfs(i + 1, j) & dfs(i - 1, j) & \
                dfs(i, j + 1) & dfs(i, j - 1) & grid1[i][j]

        ans = 0

        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1:
                 ans += dfs(i, j)

        return ans    
        
    def _countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        
        self.M = len(grid1)
        self.N = len(grid1[0])

        self.visited1 = [[0 for _ in range(self.N)] for _ in range(self.M)]
        self.visited2 = [[0 for _ in range(self.N)] for _ in range(self.M)]

        counter = 0
        for i in range(self.M):
            for j in range(self.N):
                if grid1[i][j] == 1 and grid2[i][j] == 1 and self.visited2[i][j] == 0:
                    counter += self.__dfs(grid1, grid2, i, j)
        return counter


    def __dfs(self, grid1, grid2, i, j) -> int:
        if (i < self.M and i >= 0) and (j < self.N and j >= 0) \
            and self.visited2[i][j] == 0 and grid2[i][j] == 1 and grid1[i][j] == 1: 
            
            self.visited2[i][j] = 1
            
            return self.__dfs(grid1, grid2, i+1, j) and self.__dfs(grid1, grid2, i-1, j) \
                and self.__dfs(grid1, grid2, i, j-1) and self.__dfs(grid1, grid2, i, j+1)

        return 1

if __name__ == '__main__':
    sol = Solution()

    grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]
    grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
    sl = sol.countSubIslands(grid1, grid2)

    print(sl)