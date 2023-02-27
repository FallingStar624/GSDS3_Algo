class Solution:
    def updateMatrix(self, mat):
        queue = []
        for i in range(len(mat)):
            for j in range(len(mat[0])): 
                if (mat[i][j] == 0):       
                    queue.extend([(i,j)]) 
                else:
                    mat[i][j] = -1
        print(queue)
        
        while(queue):
            curr = queue.pop()
            for d in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                row = curr[0] + d[0]
                col = curr[1] + d[1]
                if (row < 0) or (col < 0) or (row >= len(mat)) or (col >= len(mat[0])) or (mat[row][col] != -1): 
                    continue
                print('curr', curr[0], curr[1])
                print(row, col)
                mat[row][col] = mat[curr[0]][curr[1]] + 1

                print(mat)
                queue.extend([(row, col)])
        # print(mat)
        return mat


if __name__ == '__main__':
    S = Solution()
    s =  [[0,0,0],[0,1,0],[1,1,1]]
    print(S.updateMatrix(s)) # 983