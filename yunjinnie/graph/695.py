from typing import List
def maxAreaOfIsland(grid: List[List[int]]) -> int:
    row = len(grid)
    col = len(grid[0])
    #area = []
    area = 0

    visit = [[0 for j in range(col)] for i in range(row)]
    d = [(-1, 0), (1, 0), (0, -1), (0, 1)] ##

    def dfs(i, j):
        cnt = 1
        for x, y in d:
            nx, ny = x+i, y+j

            if 0<=nx<row and 0<=ny<col and visit[nx][ny]==0 and grid[nx][ny]==1:
            #cnt+=1
                visit[nx][ny] = 1 ##
                ################
                # cnt+=dfs(i+1, j)
                # cnt+=dfs(i-1, j)
                # cnt+=dfs(i, j+1)
                # cnt+=dfs(i, j-1)
                cnt += dfs(nx, ny)
        #print(cnt)
        return cnt

    for i in range(row):
        for j in range(col):
            if visit[i][j]==0 and grid[i][j]==1:
                visit[i][j]=1 ##
                area = max(area, dfs(i, j))
    return area

print(maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]]))