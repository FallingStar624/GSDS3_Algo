from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(grid, visited, m, n, i, j):
        # 같은 섬의 땅을 dfs로 체크하기
            if 0<=i<m and 0<=j<n and grid[i][j] == "1" and visited[i][j] == 0:
                visited[i][j] = 1      # visit matrix의 0을 1로 바꾸기
                dfs(grid, visited, m, n, i+1, j)   # 현재 위치 기준 오른쪽으로
                dfs(grid, visited, m, n, i-1, j)   # 현재 위치 기준 왼쪽으로
                dfs(grid, visited, m, n, i, j+1)   # 현재 위치 기준 위로
                dfs(grid, visited, m, n, i, j-1)   # 현재 위치 기준 아래로
            
        m = len(grid)
        n = len(grid[0])
        ans = 0
        visited = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                #처음 방문한 땅이면 개수 추가
                if grid[i][j] == "1" and visited[i][j] == 0:
                    ans += 1
                    dfs(grid, visited, m, n, i, j)
        return ans
