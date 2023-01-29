class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        # left right down up 
        # x-1 x+1 y-1 y+1
        row = len(image)
        col = len(image[0])
        cnt = 0
        d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        init = image[sr][sc]
        # image[sr][sc] = color

        def dfs(i, j):
            image[i][j] = color
            for y, x in d:
                dy = i+y
                dx = j+x
                if 0<=dy<row and 0<=dx<col and image[dy][dx]==init:
                    dfs(dy, dx)
        
        if init != color: # unless: out of range
            dfs(sr, sc)

        return image

# https://nova-68.tistory.com/89