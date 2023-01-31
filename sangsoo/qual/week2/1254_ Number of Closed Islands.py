# 1254
from typing import List
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        count = 0
        def dfs(r, c):
            if -1 < r < R and -1 < c < C and grid[r][c] == 0:
                grid[r][c] = 1 #visited 한 것을 1로 표시
                dfs(r, c+1)
                dfs(r, c-1)
                dfs(r+1, c)
                dfs(r-1, c)

        # 양끝을 제외시킴
        for i in range(R):
            for j in range(C):
                if(i==0 or j==0 or i==R-1 or j==C-1) and grid[i][j] ==0:
                    dfs(i,j)
        # 양끝을 제외하고 세기 시작
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 0:
                    dfs(i, j)
                    count +=1
        return count