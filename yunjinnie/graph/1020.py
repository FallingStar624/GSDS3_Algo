class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        area = 0
        d=[(-1, 0), (1, 0), (0, 1), (0, -1)]
        visit = [[0 for j in range(col)] for i in range(row)]
        # # of island, out of edge (dfs 돌면서 visit 처리로 제거)
        
        def dfs(i, j):
            visit[i][j]=1
            for x, y in d:
                nx, ny = x+i, y+j
                if 0<=nx<row and 0<=ny<col and visit[nx][ny]==0 and grid[nx][ny]==1: 
                    visit[nx][ny]=1
                    dfs(nx, ny)
            
        for i in range(row):
            for j in range(col):
                if i==0 or j==0 or i==row-1 or j==col-1:
                    if grid[i][j]==1:
                        dfs(i, j)
              
        for i in range(row):
            for j in range(col):
                if grid[i][j]==1 and visit[i][j]==0:
                    #dfs(i, j, area) -> island 개수 셀 때 (1254)
                    area+=1 # 면적 구할 때는 dfs 하면서 visit 처리 하면 안됨

        return area


# https://www.youtube.com/watch?v=3S63TTd3Ck4