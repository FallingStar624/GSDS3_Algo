class Solution:
    def color(self, image, sr, sc, newcolor, oldcolor):
      if self.finish(sr, sc, image): 
        return

      check = [(sr-1, sc), (sr+1, sc), (sr, sc-1), (sr, sc+1)] 
      if image[sr][sc] == oldcolor:
        image[sr][sc] = newcolor
        for i in check:
          self.color(image, i[0], i[1], newcolor, oldcolor)

    def finish(self, sr, sc, image):
      if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]): 
        return True
      else:
        return False

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
      # ans = image
      oldcolor = image[sr][sc]
      if image[sr][sc] != color:
        self.color(image, sr, sc, color, oldcolor)

      return image
