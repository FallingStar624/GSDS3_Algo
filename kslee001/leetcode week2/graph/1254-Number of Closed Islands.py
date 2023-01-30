from typing import Optional, List
class Solution:
    
    # OOB
    def OOB(self, x, limit):
        return (x<0) | (x>=limit) # | 혹은 & 사용시 괄호에 조건 넣는 것 조심하기
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        # DXDY 
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]

        # board
        Y = len(grid)
        X = len(grid[0])
        G = grid
        V = [[False for _ in range(X)] for _ in range(Y)]

        stack = list()                
        num_islands = 0

        for y in range(Y):
            for x in range(X):
                # visit check
                if V[y][x] ==True:
                    continue # visited
                if G[y][x] ==1: 
                    continue # water

                stack.append( (y, x) )
                is_bound = False # --> flag for NOT closed islands

                while(stack):
                    cur_y, cur_x = stack.pop() # right pop : FILO
                    if V[cur_y][cur_x] == True:
                        continue # visit check
                    V[cur_y][cur_x] = True
                    for d in range(4):
                        new_y = cur_y + dy[d]
                        new_x = cur_x + dx[d]
                        # oob check
                        if (self.OOB(new_y, Y)) | (self.OOB(new_x, X)):
                            is_bound = True
                            continue
                        if G[new_y][new_x]==1:
                            continue

                        stack.append((new_y, new_x))

                if is_bound == False:
                    num_islands +=1
        return num_islands