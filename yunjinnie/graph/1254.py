from typing import List
def closedIsland(grid: List[List[int]]) -> int:
    row = len(grid)
    col = len(grid[0])
    cnt = 0

    visit = [[0 for j in range(col)] for i in range(row)]

    def dfs(i, j):
        if 0<=i<row and 0<=j<col and grid[i][j]==0 and visit[i][j]==0:
            visit[i][j]=1
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

    # make edge visited
    for i in range(row):
        for j in range(col):
            if i==0 or j==0 or i==row-1 or j==col-1:
                if grid[i][j]==0:
                    dfs(i, j)

    for i in range(row):
        for j in range(col):
            if grid[i][j]==0 and visit[i][j]==0:
                cnt+=1
                dfs(i, j)

    return cnt

print(closedIsland([[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]))
# https://walkccc.me/LeetCode/problems/1254/