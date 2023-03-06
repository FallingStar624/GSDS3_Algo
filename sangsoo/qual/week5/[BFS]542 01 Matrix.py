# 542. 01 Matrix(BFS)
# failed, solution
'''
Algorithm
1. 0에서부터 BFS 시작
2. -1을 만날때까지 거리를 잰다.

처음에 생각한 Algorithm (망함)
1. 모든 자리에서 BFS 시작
2. 0을 만나면 count 정지하고 distance 기록
-> 안되었던 이유
  거리가 중복이되어서 측정이 안된다... 
'''
from collections import deque
from typing import List


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        R = len(mat)
        C = len(mat[0])
        drow = [1, -1, 0, 0]
        dcol = [0, 0, 1, -1]

        q = deque()
        for r in range(R):
            for c in range(C):
                if mat[r][c] == 0:
                    q.append((r, c))
                else:
                    mat[r][c] = -1  

        while q:
            r, c = q.popleft()
            for i in range(4):
                nrow, ncol = r + drow[i], c + dcol[i]
                if 0 <= nrow < R and 0 <= ncol < C and mat[nrow][ncol] == -1:
                    mat[nrow][ncol] = mat[r][c] + 1
                    q.append((nrow, ncol))
        return mat