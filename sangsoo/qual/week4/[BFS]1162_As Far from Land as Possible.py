# 1162. As Far from Land as Possible (BFS Breadth First Search)
# failed, solution
'''
[Algorithm]
(문제요구사항) 1에서 가장 먼 0을 찾아라
1. 1을 기준으로 BFS를 한다. 
2. BST를 하면서 0을 1로 바꿔준다.
3. 모두 1이 바뀌면 while문을 종료한다.
4. BST를 한번 할때마다 distance를 1씩 더해줘서 최종적으로 모두 더해진 값이 거리가 된다. 
'''
from collections import deque
from typing import List
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # number of rows and columns in the grid
        n = len(grid)
        # variable to keep track of the maximum distance
        dist = 0
        # queue to keep track of the cells to be processed
        q = deque()
        # arrays to keep track of the row and column movements
        drow = [0, -1, 0, 1]
        dcol = [-1, 0, 1, 0]
        
        # loop through the grid to add all the land cells to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j))
        # if the entire grid is land, return -1
        if len(q) == n*n:
            return -1
        
        # loop until the queue is empty
        while q:
            # get the size of the queue for the current level of the BFS
            size = len(q)
            # increment the distance
            dist += 1
            # loop through the size of the queue
            for _ in range(size):
                # get the next cell to be processed
                r, c = q.popleft()
                # loop through the 4 possible movements
                for i in range(4):
                    nrow, ncol = r + drow[i], c + dcol[i]
                    # if the new cell is within the grid and is a water cell
                    if 0 <= nrow < n and 0 <= ncol < n and grid[nrow][ncol] == 0:
                        # mark the new cell as land(1)
                        grid[nrow][ncol] = 1
                        # add the new cell to the queue for processing
                        q.append((nrow, ncol))
        # return the maximum distance minus 1, as the initial distance is set to 1
        return dist - 1