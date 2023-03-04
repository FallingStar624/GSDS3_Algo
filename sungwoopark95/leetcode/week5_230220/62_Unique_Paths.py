class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        array = [[0 for _ in range(n)] for _ in range(m)]
        if m == 1 and n == 1:
            return 1
        if m > 1:
            array[1][0] = 1
        if n > 1:
            array[0][1] = 1

        for i in range(2, m):
            array[i][0] = array[i-1][0]
        for j in range(2, n):
            array[0][j] = array[0][j-1]
        for i in range(1, m):
            for j in range(1, n):
                array[i][j] = array[i-1][j] + array[i][j-1]

        # print(array)
        return array[m-1][n-1]
