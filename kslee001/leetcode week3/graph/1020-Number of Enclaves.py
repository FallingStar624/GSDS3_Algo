from typing import List

class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        # return value
        res = 0
        
        # settings
        G = grid
        Y = len(G)
        X = len(G[0])
        V = [[False for _ in range(X)] for _ in range(Y)]
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]
        
        for y in range(Y):
            for x in range(X):
                # visit?
                if V[y][x] == True:
                    continue
                # water?
                if G[y][x] == 0:
                    V[y][x] = True
                    continue
                
                # BFS
                queue = []
                queue.append((y, x))
                V[y][x] = True # visit
                
                cur_area = 0 # current area
                flag = False # flag to detect islands on the edge
                while(queue):
                    cy, cx = queue.pop(0)
                    cur_area +=1
                    
                    for d in range(4):
                        ny, nx = cy+dy[d], cx+dx[d]
                        
                        # OOB
                        if (ny<0) | (ny>=Y):
                            flag = True
                            continue
                        if (nx<0) | (nx>=X):
                            flag = True
                            continue
                        
                        # visit check
                        if V[ny][nx] == True:
                            continue
                        
                        # water check
                        if G[ny][nx] == 0:
                            V[ny][nx] = True
                            continue
                
                        # push
                        V[ny][nx] = True
                        queue.append((ny,nx))
                
                if flag == True: # island on the edge of the map
                    continue
                else:
                    res += cur_area
                        
        return res