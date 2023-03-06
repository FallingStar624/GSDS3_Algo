# 70. Climbing Stairs (Bottom-up DP)
class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0 for _ in range(n+1)]
        if n < 4:
            return n
        memo[1], memo[2], memo[3] = 1, 2, 3
        for i in range(4, n+1):
            memo[i] = memo[i-1] + memo[i-2]
        return memo[n]