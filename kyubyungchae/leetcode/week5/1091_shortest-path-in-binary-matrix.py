from typing import List

from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

        if grid[0][0] != 0 or grid[-1][-1] != 0:
            return -1

        q = deque()
        dirs = [(1,0),(-1,0),(1,1),(-1,-1),(1,-1),(-1,1),(0,-1),(0,1)]

        q.append((0,0))
        visited = {(0,0)}

        dist = 1
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                if x == len(grid)-1 and y == len(grid[0])-1:
                    return dist

                for dx, dy in dirs:
                    nx = x + dx
                    ny = y + dy
                    
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) \
                          and grid[nx][ny] == 0 and (nx,ny) not in visited:
                        visited.add((nx, ny))
                        q.append((nx,ny))
            dist += 1

        return -1
    


if __name__ == '__main__':
    sol = Solution()
    grid = [[0,1],[1,0]]
    print(sol.shortestPathBinaryMatrix(grid))