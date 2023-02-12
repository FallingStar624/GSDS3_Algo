class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # (r, c)에서 상하좌우 dfs했을 때 각각 po, ao에 닿을 수 있는가
        row = len(heights)
        col = len(heights[0])
        pvisit = [[0 for j in range(col)] for i in range(row)]
        avisit = [[0 for j in range(col)] for i in range(row)]
        
        d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        
        def dfs(visit, i, j):
            visit[i][j]=1
            for x, y in d:
                nx, ny = x+i, y+j
                
                if 0<=nx<row and 0<=ny<col and visit[nx][ny]==0 and heights[nx][ny]>=heights[i][j] :
                    #visit[nx][ny]=1
                    dfs(visit, nx, ny)
                    
                    
        for i in range(row):
            dfs(pvisit, i, 0) # p - left
            dfs(avisit, i, col-1) # a - right
            
        for j in range(col):
            dfs(pvisit, 0, j) # p - up
            dfs(avisit, row-1, j) # a - under
            
        return [[i, j] for j in range(col) for i in range(row)
               if pvisit[i][j] and avisit[i][j]]


# https://zhenyu0519.github.io/2020/03/18/lc417/