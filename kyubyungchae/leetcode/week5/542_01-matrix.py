from typing import List
from collections import deque

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:

        M = len(mat)
        N = len(mat[0])
        q = deque()
        dirs = [(1,0),(0,1),(-1,0),(0,-1)]

        for i in range(M):
            for j in range(N):
                if mat[i][j] == 0:
                    q.append((i,j))
                else:
                    mat[i][j] = -1

        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < M and 0 <= ny < N and mat[nx][ny] == -1:
                    mat[nx][ny] = mat[x][y] + 1
                    q.append((nx, ny))
            
        return mat


if __name__ == '__main__':
    sol = Solution()
    mat = [[0,0,0],[0,1,0],[1,1,1]]
    print(sol.updateMatrix(mat))