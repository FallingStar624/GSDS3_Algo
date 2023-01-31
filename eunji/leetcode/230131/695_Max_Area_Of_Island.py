class Solution:
    def finish(self, grid, i, j):
      if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
        return True
      return False

    def AreaofIsland(self, grid, i, j, is_checked):
      if self.finish(grid, i, j): 
        return 0
      size = 0
      check = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)] 
      if grid[i][j] == 1:
        size += 1
        grid[i][j] = 2
        for c in check:
          size += self.AreaofIsland(grid, c[0], c[1], is_checked)
      return size

    def maxAreaOfIsland(self, grid):
      ans = 0
      is_checked = 2
      for i in range(len(grid)):
        for j in range(len(grid[0])):
          if (grid[i][j] == 1):
            new = self.AreaofIsland(grid, i, j, is_checked)
            if (new > ans):
              ans = new
      return ans