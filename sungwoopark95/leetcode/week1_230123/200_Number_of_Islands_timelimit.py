from typing import List

## visited를 list로 처리하면 timelimit
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = []
        stack = []
        m, n = len(grid), len(grid[0])                  # m: row / n: col
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] # 상하좌우
        count = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and (i, j) not in visited:
                    count += 1
                    visited.append((i, j))
                    stack.append((i, j))
                    while stack:
                        curX, curY = stack.pop(-1)
                        for d in directions:
                            dx, dy = d
                            newX, newY = curX + dx, curY + dy
                            if newX < 0 or newX >= m or newY < 0 or newY >= n: continue
                            if (newX, newY) in visited or grid[newX][newY] == "0": continue
                            visited.append((newX, newY))
                            stack.append((newX, newY))

        return count