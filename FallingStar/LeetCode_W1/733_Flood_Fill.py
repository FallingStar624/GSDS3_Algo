from typing import List
from collections import deque


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        cols = len(image[0])
        rows = len(image)
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        same = image[sr][sc]
        q = deque([(sr, sc)])
        while q:
            cr, cc = q.popleft()
            image[cr][cc] = color
            visited[cr][cc] = True
            for d in range(4):
                nr, nc = cr+dr[d], cc+dc[d]
                if -1 < nr < rows and -1 < nc < cols:
                    if image[nr][nc] == same and not visited[nr][nc]:
                        q.append((nr, nc))
        return image

