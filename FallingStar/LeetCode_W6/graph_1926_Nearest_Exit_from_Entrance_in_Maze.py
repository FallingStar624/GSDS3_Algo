from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m = len(maze)
        n = len(maze[0])
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        ans = 0
        q = deque([(entrance[0], entrance[1])])
        seen = {(entrance[0], entrance[1])}

        while q:
            ans += 1
            for _ in range(len(q)):
                cr, cc = q.popleft()
                for d in range(4):
                    nr = cr + dr[d]
                    nc = cc + dc[d]
                    if -1 < nr < m and -1 < nc < n:
                        if (nr, nc) not in seen and maze[nr][nc] != '+':
                            if nr == 0 or nr == m - 1 or nc == 0 or nc == n - 1:
                                return ans
                            q.append((nr, nc))
                            seen.add((nr, nc))

        return -1

