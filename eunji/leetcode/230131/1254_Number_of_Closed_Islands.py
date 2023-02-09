class Solution:
    def edge2island(self, grid, e):
      i = e[0]
      j = e[1]
      if self.finish(grid, i, j):
        return
      if grid[i][j] == 0:
        grid[i][j] = 1
        check = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)] 
        for c in check:
          self.edge2island(grid, c)

    def finish(self, grid, i, j):
      if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]):
        return True
      return False

    def closedIslandCheck(self, grid, i, j, isChecked):
      if self.finish(grid, i, j):
        return
      if grid[i][j] == 0:
        grid[i][j] = 2
        check = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)] 
        for c in check:
          self.closedIslandCheck(grid, c[0], c[1], isChecked)

    def closedIsland(self, grid):
      ans = 0
      isChecked = 2
      numIsland = 0
      # make the water by the edge into island
      edge = []
      for i in range(len(grid)):
        edge.append((i, 0))
        edge.append((i, len(grid[0])-1))
      for i in range(len(grid[0])):
        edge.append((len(grid)-1, i))
        edge.append((0, i))
      for e in edge:
        self.edge2island(grid, e)
      # print(grid)
      for i in range(len(grid)):
        for j in range(len(grid[0])):
          if grid[i][j] == 0:
            numIsland += 1
            self.closedIslandCheck(grid, i, j, isChecked)
      # print(grid)

      return numIsland

