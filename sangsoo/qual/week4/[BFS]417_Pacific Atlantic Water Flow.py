# 417. Pacific Atlantic Water Flow
# refer to the solution
'''
[Algorithm]
(문제요구사항) atlantic, pacific으로 흐를 수 있는 지점들을 찾아라...!
1. (1줄 요약)atlantic, pacific으로 갈수 있는 곳을 찾고 intersection해서 구한다
2. atlantic, pacific으로 갈수 있는 가장 가까운 곳은 각 해변(가장자리)이다
3. 각 가장자리부터 BST를 하면서 각 queue에 넣게 되는데... 
4. 이때 본인보다 같거나 높아야 흐르게 되니까 본인보다 같거나 높으면 추가 아니면 추가하지 않는다.
5. 최종적으로 atlantic, pacific으로 각각 흐르게 되는 곳이 각각의 set에 더해지면, 
6. intersection해서 return한다. 
'''
from collections import deque
from typing import List
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        R, C = len(heights), len(heights[0])
        # Check if input is empty
        if not R or not C:
            return []

        pacific_q = deque()
        atlantic_q = deque()
        # check for each beach with left, right side
        for i in range(R):
            pacific_q.append((i, 0)) # left column for pacific
            atlantic_q.append((i, C-1))  # right column for atlantic
        #check for each beach with top, bottom side
        for i in range(C):
            pacific_q.append((0, i)) # left column for pacific
            atlantic_q.append((R-1, i)) # bottom row for atlantic
        
        def bfs(queue):
            reachable = set()
            drow = [0, -1, 0, 1]
            dcol = [-1, 0, 1, 0]
            while queue:
                r, c = queue.popleft()
                # This cell is reachable, so mark it
                reachable.add((r, c))
                for i in range(4):
                    nrow, ncol = r + drow[i], c + dcol[i] # check all 4 directions
                    # check if the new cell is within bounds
                    if nrow < 0 or nrow >= R or ncol < 0 or ncol >= C:
                        continue
                    # check that the new cell hasn't already been visited
                    if (nrow, ncol) in reachable:
                        continue
                    # check that the new cell has higher or equal height,
                    # so that water can flow the new cell to the old cell
                    if heights[nrow][ncol] < heights[r][c]:
                        continue
                    # if we've gotten this far, that means the new cell is reachable
                    queue.append((nrow, ncol))
            return reachable
        
        # Perform a BFS for each ocean to find all cells accessible by each ocean
        pacific_reachable = bfs(pacific_q)
        atlantic_reachable = bfs(atlantic_q)

        # Finde all cells that can reach both oceans, and convert to list
        # intersection is a attribute of set container
        return list(pacific_reachable.intersection(atlantic_reachable)) 