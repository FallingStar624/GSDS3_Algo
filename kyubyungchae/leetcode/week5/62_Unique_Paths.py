
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

        def helper(x, y):
            if x == 1 or y == 1:
                return 1
            
            if dp[x][y]:
                return dp[x][y]
            
            up = helper(x - 1, y)
            left = helper(x, y - 1)

            dp[x][y] = up + left
            return dp[x][y]
    
        return helper(m ,n)
    

if __name__ == '__main__':
    sol = Solution()
    m = 3
    n = 7
    print(sol.uniquePaths(m,n))