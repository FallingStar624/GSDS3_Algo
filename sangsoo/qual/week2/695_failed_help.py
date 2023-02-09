# 695_failed
# 왜 안되는거임..? maximum recursion depth라는데.... 허허
from typing import List
class Solution:
    def __init__(self):
        self.num = 0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = set()
        R = len(grid)
        C = len(grid[0])
        def dfs(r, c):
            if -1 < r < R and -1 < c < C and (r,c) not in visited:
                if grid[r][c] == 0:
                    return 0
                else:
                    visited.add(grid[r][c])
                    return 1 + dfs(r, c-1) + dfs(r, c+1) + dfs(r+1, c) + dfs(r-1, c)
            return 0
        for i in range(R):
            for j in range(C):
                self.num = max(self.num, dfs(i, j))
        return self.num