class Solution:
    def finish(self, grid, i, j):
      if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
        return True
      return False

    def AreaofIsland(self, grid, i, j):
      if self.finish(grid, i, j): 
        return 
      check = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)] 
      if grid[i][j] == 1:
        grid[i][j] = 0
        for c in check:
          self.AreaofIsland(grid, c[0], c[1])

    def numEnclaves(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == 1) & ((i == 0) or (j == 0) or (i == len(grid)-1) or (j == len(grid[0])-1)):
                    self.AreaofIsland(grid, i, j)
        return sum([sum(i) for i in grid]) 
