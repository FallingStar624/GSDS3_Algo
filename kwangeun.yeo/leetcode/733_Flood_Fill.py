class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        return self.bfs(image, sr, sc, color)
    
    def bfs(self, image, sr, sc, trg):
        src = image[sr][sc]
        n_row = len(image)
        n_col = len(image[0])
        visit = [[0] * n_col for _ in range(n_row)]
        dr = [1, 0, -1, 0]
        dc = [0, 1, 0, -1]
        
        q = []
        image[sr][sc] = trg
        visit[sr][sc] = 1
        q.append([sr, sc])
        while q:
            cr, cc = q.pop()
            for mr, mc in zip(dr, dc):
                nr = cr + mr
                nc = cc + mc
                if nr < 0 or nc < 0 or nr >= n_row or nc >= n_col:
                    continue
                if visit[nr][nc]:
                    continue
                if image[nr][nc] != src:
                    continue
                image[nr][nc] = trg
                visit[nr][nc] = 1
                q.append([nr, nc])
        return image