# 695
from typing import List
class Solution:
    def __init__(self):
        self.num = 0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        def dfs(r, c):
            if -1 < r < R and -1 < c < C :
                if grid[r][c] == 0:
                    return 0
                else:
                    grid[r][c] = 0 # visit한 것을 0으로 표시해줌.
                    return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c-1) + dfs(r, c+1) 
            return 0
        for i in range(R):
            for j in range(C):
                self.num = max(self.num, dfs(i, j))
        return self.num