from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        visited = []
        stack = []
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        n = len(image)
        m = len(image[0])

        visited.append((sr, sc))
        stack.append((sr, sc))
        starting_color = image[sr][sc]
        image[sr][sc] = color

        while stack:
            curX, curY = stack.pop(-1)
            for d in directions:
                dx, dy = d
                newX, newY = curX + dx, curY + dy
                if newX < 0 or newX >= n or newY < 0 or newY >= m: continue
                if (newX, newY) in visited or image[newX][newY] != starting_color: continue
                image[newX][newY] = color
                visited.append((newX, newY))
                stack.append((newX, newY))

        return image