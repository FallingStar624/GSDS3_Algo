class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        A = [[0 for _ in range(n)] for _ in range(m)]
        for y in range(m):
            A[y][0] = 1
        for x in range(n):
            A[0][x] = 1
        for y in range(1, m):
            for x in range(1, n):
                A[y][x] = A[y-1][x] + A[y][x-1]
        return A[m-1][n-1]
                