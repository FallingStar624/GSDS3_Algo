from typing import List
from collections import deque

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        M = len(grid)
        N = len(grid[0])
        
        dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        q = deque()
        for i in range(M):
            for j in range(N):
                if grid[i][j] == 1:
                    q.append((i, j))
        dist = -1

        if not q or len(q) == M * N:
            return dist
        
        while q:
            size = len(q)
            dist += 1
            while size:
                size -= 1
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < M and 0 <= ny < N and grid[nx][ny] == 0:
                        grid[nx][ny] = 1
                        q.append((nx, ny))

        return dist


if __name__ == '__main__':

    sol = Solution()
    grid = [[1,0,1],[0,0,0],[1,0,1]]
    print(sol.maxDistance(grid))