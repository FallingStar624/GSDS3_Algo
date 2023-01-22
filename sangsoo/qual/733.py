class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        R, C = len(image), len(image[0]) # max row, max column
        color = image[sr][sc] # starting pixel

        def dfs(r, c):
            print(f"r : {r}, c : {c}")
            if r < 0 or r >= R or c < 0 or c >= C: # out of bounds
                return
            if image[r][c] == newColor: # already changed
                return
            if image[r][c] != color: # not starting color
                return
            if image[r][c] == color: # same with stating color
                image[r][c] = newColor
            # up, down, left, right
            dfs(r-1, c)
            dfs(r+1, c)
            dfs(r, c-1)
            dfs(r, c+1)
        dfs(sr, sc)
        print(image)
        return image

sol = Solution()
sol.floodFill(image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2)