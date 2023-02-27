# 70. Climbing Stairs (Top-down DP)
class Solution:
    def climbStairs_help(self, n:int, memo:list) -> int:
        if n < 4:
            return n
        if memo[n] == 0:
            memo[n] = self.climbStairs_help(n-1, memo) + self.climbStairs_help(n-2, memo)
        return memo[n]

    def climbStairs(self, n: int) -> int:
        return self.climbStairs_help(n, [0 for _ in range(n+1)])