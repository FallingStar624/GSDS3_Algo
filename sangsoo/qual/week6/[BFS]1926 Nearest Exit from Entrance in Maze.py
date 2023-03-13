# 1926. Nearest Exit from Entrance in Maze (BFS)
'''
Algorithm
1. enrance에서 BFS
2. border 도착하면 return distance
edge case
- example 2처럼 시작지점 반대로 갈수 있는 것.
1091번과 비슷한 문제
'''
from collections import deque
from typing import List
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        R, C = len(maze), len(maze[0])
        er, ec = entrance[0], entrance[1]
        q = deque()

        drow = [1, -1, 0, 0]
        dcol = [0, 0, 1, -1]

        # 시작지점에서 아예 나갈수 조차 없으면 -1
        if er == 0 or er == R or ec == 0 or ec == C:
            tmp = [1 for _ in range(4)]
            for i in range(4):
                nrow, ncol = er + drow[i], ec + dcol[i]
                if nrow == -1 or nrow == R or ncol == -1 or ncol == C or maze[nrow][ncol] == '+':
                    tmp[i] = 1
                else:
                    tmp[i] = 0
            if tmp[0]+tmp[1]+tmp[2]+tmp[3] == 4:
                return -1
        # 처음에는 이렇게 풀었는데, 이 위에 10줄을 그냥 maze[er][ec] = '+' 로 바꿔주면 끝나는 거였음... ㅜㅜ
        d = 0
        q.append((er, ec, d))
        # 시작지점이 아니고 벽에 도착 하면 return -1
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
