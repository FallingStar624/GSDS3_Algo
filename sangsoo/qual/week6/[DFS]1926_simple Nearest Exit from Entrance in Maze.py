# 1926. Nearest Exit from Entrance in Maze (BFS)
from collections import deque
from typing import List
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        R, C = len(maze), len(maze[0])
        er, ec = entrance[0], entrance[1]
        q = deque()

        drow = [1, -1, 0, 0]
        dcol = [0, 0, 1, -1]
        maze[er][ec] = '+'

        d = 0 
        q.append((er, ec, d))
        while q:
            r, c, d = q.popleft()
            if ((r, c) != (er, ec)) and  (r == 0 or r == R-1 or c == 0 or c == C-1):
                return d
            for i in range(4):
                nrow, ncol = r + drow[i], c + dcol[i]
                if 0 <= nrow < R and 0 <= ncol < C and maze[nrow][ncol] == '.':
                    maze[nrow][ncol] = '+' 
                    q.append((nrow, ncol, d+1))
        return -1            