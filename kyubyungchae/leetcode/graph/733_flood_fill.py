from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        self.M = len(image)
        self.N = len(image[0])
        self.image = image
        self.visited = [[0 for _ in range(self.N)] for _ in range(self.M)]
        start_color = image[sr][sc]
        self.__dfs(sr, sc, start_color, color)

        return self.image

    def __dfs(self, i ,j, start_color, color):
        if (i < self.M and i >= 0) and (j < self.N and j >= 0) \
            and self.image[i][j] == start_color and self.visited[i][j] == 0:

            self.visited[i][j] = 1
            self.image[i][j] = color
            self.__dfs(i-1, j, start_color, color)
            self.__dfs(i+1, j, start_color, color)
            self.__dfs(i, j-1, start_color, color)
            self.__dfs(i, j+1, start_color, color)


if __name__ == '__main__':

    sol = Solution()
    image = [[0,0,0],[0,0,0]]
    sr = 1; sc = 0; color = 2

    sl = sol.floodFill(image, sr, sc, color)
    print(sl)