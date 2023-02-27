class Solution:

    def climbStairs(self, n: int) -> int:

        if n == 1:
            return 1

        self.dp = [0 for _ in range(n+1)]

        self.dp[1] = 1
        self.dp[2] = 2

        for i in range(3, n+1):
            self.dp[i] = self.dp[i-1] + self.dp[i-2]
        

        return self.dp[n]
    

if __name__ == '__main__':

    sol = Solution()
    n = 4
    print(sol.climbStairs(n))