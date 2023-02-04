from typing import List


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:

        res = 0
        # visit -> 2
        Y = len(grid1)
        X = len(grid1[0])
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]
        
        for y in range(Y):
            for x in range(X):
                # visit check
                if grid1[y][x] == 2:
                    continue
                # water check
                if grid1[y][x] == 0:
                    grid1[y][x] = 2;
                    continue
                
                queue = []
                queue.append((y,x))
                grid1[y][x] = 2 # visit
                
                current_is = []
                while(queue):
                    cy,cx = queue.pop(0)
                    current_is.append((cy, cx))
                    
                    for d in range(4):
                        ny, nx = cy+dy[d], cx+dx[d]
                        # OOB
                        if (ny<0) | (ny>=Y) | (nx<0) | (nx>=X):
                            continue
                        # visit
                        if grid1[ny][nx] == 2:
                            continue
                        # water
                        if grid1[ny][nx] == 0:
                            grid1[ny][nx] = 2
                            continue
                        
                        grid1[ny][nx] = 2
                        queue.append((ny,nx))
                    
                # grid 2

                for cy, cx in current_is:
                    # visit check
                    if grid2[cy][cx] == 2:
                        continue
                    # water check
                    if grid2[cy][cx] == 0:
                        grid2[cy][cx] = 2
                        continue

                    flag = False # expanded?
                    queue.append((cy, cx))
                    grid2[cy][cx] = 2
                    
                    while(queue):
                        ccy, ccx = queue.pop(0)
                        for d in range(4):
                            ny, nx = ccy+dy[d], ccx+dx[d]
                            # OOB
                            if (ny<0)|(ny>=Y)|(nx<0)|(nx>=0):
                                continue
                            # visit
                            if grid2[ny][nx] == 2:
                                continue
                            # water
                            if grid2[ny][nx] == 0:
                                grid2[ny][nx] = 2
                                continue
                                
                            # expanded islands -> not sub-islands
                            if ((ny,nx) not in current_is):
                                flag = True
                            queue.append((ny, nx))
                            
                if flag == False:
                    res += 1
                        
        return res