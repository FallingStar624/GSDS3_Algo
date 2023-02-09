# solution 보고 작성
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        count = 0
        # dfs가 끝나면서 count 1개씩 하는 방식
        # dfs 들어가면서 다 #으로 바꿔주고 나오면서 count 1해줌
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count +=1
        return count

    def dfs(self, grid, i, j):
        # 상하좌우 범위 벗어나면 패스 그리고 1이면 패스
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] != '1':
            return
        grid[i][j] = "#"
        self.dfs(grid, i+1, j)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i, j-1)
        