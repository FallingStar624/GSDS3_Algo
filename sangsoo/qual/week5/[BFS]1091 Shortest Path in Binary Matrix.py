# 1091. Shortest Path in Binary Matrix(BFS)
'''
Algorithm
1. BFS 돌면서 dist 증가
2. (n-1, n-1) 도달하면 return dist
3. distance도 q에 넣어줘야지 중복된 경로에서 짧은 값을 return할 수 잇음.
** 1162번 문제와 비슷한 문제(BFS)
'''
from collections import deque
from typing import List
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque()
        if (grid[0][0] == 1):
            return -1
        d = 1
        q.append((0,0,d)) # r, c, distance

        drow = [1, 1, 0, 0, -1, -1, 1, -1]
        dcol = [1, 0, 1, -1, 0, 1, -1, -1] 
        grid[0][0] = 1

        while q:
            (r, c, d) = q.popleft()
            if((r == n-1) and (c == n-1)):
                return d

            for i in range(8):
                nrow, ncol = r + drow[i], c + dcol[i]
                if 0 <= nrow < n and 0 <= ncol < n and grid[nrow][ncol] == 0:
                    grid[nrow][ncol] = 1
                    q.append((nrow, ncol, d+1))
        return -1            
