from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # dfs call (step) 수 최다인 곳 기록 xxx
        # bfs
        row = len(grid)
        col = len(grid[0])
        
        d = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        #visit = [[0 for j in range(col)] for i in range(row)]
        visit = deque([(x, y) for x in range(col) for y in range(row) if grid[x][y]==1])
        ans = 0
        
        def manhattan(x0, y0, x1, y1):
            return(abs(x0-x1) + abs(y0-y1))
        
        #def dfs(visit, i, j, ans):
        while visit:
            #visit[i][j]=1
            i, j = visit.popleft()
            for x, y in d:
                nx, ny = i+x, j+y
                
                if 0<=nx<row and 0<=ny<col and grid[nx][ny]==0:
                    #ans = max(ans, manhattan(nx, ny, i, j))
                    grid[nx][ny] = grid[i][j]+1
                    visit.append((nx, ny))
                    ans = max(ans, grid[nx][ny])
                    
        # for i in range(row):
        #     for j in range(col):
        #         dfs(visit, i, j, ans)
                
        
        return ans-1 # 1 2 3 -> step 2
        

# https://svkoreans.com/board_eng/857