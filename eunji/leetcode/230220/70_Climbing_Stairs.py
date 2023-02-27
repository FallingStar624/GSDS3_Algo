class Solution:
    def climbStairs(self, n: int) -> int:
      dp = [1, 2]
      if n == 1 or n == 2:
        return dp[n-1]

      for i in range(2, n):
        new = dp[i-1] + dp[i-2]
        dp.append(new)
      return dp[n-1]
