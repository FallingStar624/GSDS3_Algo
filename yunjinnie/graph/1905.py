class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        
        row = len(grid1) # m
        col = len(grid1[0]) # n
        ans = 0
        d = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        
        # area that 1 contains 2
        # 2의 1마다 dfs 돌면서 (visit 후 0)
        # 1에서 해당좌표값이 1인지 확인 (0이면 포함하지 않는다는 것)
        
        def dfs(island, i, j):
            # visited
            grid2[i][j]=0
            island.append((i, j))
            for x, y in d:
                nx, ny = x+i, y+j

                if 0<=nx<row and 0<=ny<col and grid2[nx][ny]==1:
                    dfs(island, nx, ny)
                    
        for i in range(row):
            for j in range(col):
                if grid2[i][j]==1:
                    island=[]
                    dfs(island, i, j)
                    if all(grid1[x][y]==1 for x, y in island):
                        ans+=1
        return ans
        
# https://leetcode.ca/2021-07-29-1905-Count-Sub-Islands/