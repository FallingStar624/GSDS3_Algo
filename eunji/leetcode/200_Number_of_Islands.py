class Solution:
    def finish(self, sr, sc, grid):
      if sr < 0 or sr >= len(grid) or sc < 0 or sc >= len(grid[0]): 
        return True
      else:
        return False

    def color(self, grid, sr, sc, is_checked, is_island):
      if self.finish(sr, sc, grid): 
        return

      check = [(sr-1, sc), (sr+1, sc), (sr, sc-1), (sr, sc+1)] 
      if grid[sr][sc] == is_island:
        grid[sr][sc] = is_checked
        for i in check:
          self.color(grid, i[0], i[1], is_checked, is_island)

    def numIslands(self, grid: List[List[str]]) -> int:
      island_num = 0
      sr = 0
      sc = 0
      is_checked = "2"
      is_island = "1"

      for i in range(len(grid)):
        for j in range(len(grid[0])):
          if grid[sr][sc] == "1":
            island_num += 1
            self.color(grid, sr, sc, is_checked, is_island)

      return island_num