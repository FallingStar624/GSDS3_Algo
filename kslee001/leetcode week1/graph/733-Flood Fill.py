from typing import *

class Solution:
    def floodFill(self, image, sr, sc, color):
        origin_color = image[sr][sc]
        print(origin_color)
        ynum = len(image)
        xnum = len(image[0])
        dy = [1,0,-1,0]
        dx = [0,1,0,-1]
        
        V = [[False for _ in range(xnum)] for _ in range(ynum)]    

        queue = []
        queue.append((sr, sc))
        while(queue):
            # pop (front)
            cur = queue.pop(0)
            y, x = cur
            
            # coloring
            image[y][x] = color
            
            # visit
            V[y][x] = True
            
            for idx in range(4):
                newy = y + dy[idx]
                newx = x + dx[idx]   
                
                # check out of bounds
                if (newy>=ynum) | (newy<0) :
                    continue
                if (newx>=xnum) | (newx<0) :
                    continue
                # check visit
                if V[newy][newx] == True:
                    continue
                # check color
                if image[newy][newx] != origin_color:
                    continue
                queue.append((newy, newx))
                    
        return image