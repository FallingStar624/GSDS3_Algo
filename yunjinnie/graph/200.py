class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid) # i=4
        col = len(grid[0]) # j=5
        cnt = 0

        visit = [[0 for j in range(col)] for i in range(row)]

        def dfs(i, j):
            if 0<=i<row and 0<=j<col and grid[i][j]=="1" and visit[i][j]==0:
                visit[i][j]=1
                dfs(i+1, j)
                dfs(i-1, j)
                dfs(i, j+1)
                dfs(i, j-1)

        for i in range(row):
            for j in range(col):
                if grid[i][j]=="1" and visit[i][j]==0:
                    cnt+=1
                    dfs(i, j)

        return cnt

# print(P4([
#     ["1","1","1","1","0"],
#     ["1","1","0","1","0"],
#     ["1","1","0","0","0"],
#     ["0","0","0","0","0"]
# ]))

# print(P4([
#     [1,1,1,1,0], 
#     [1,0,0,1,0], 
#     [1,1,0,1,0], 
#     [1,1,0,0,0]]) )
