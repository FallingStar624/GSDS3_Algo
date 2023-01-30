class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0 for _ in range(n)] for _ in range(3)]
        dp[0][0] = prices[0]
        dp[1][0] = 0
        dp[2][0] = 0
        for i in range(1, n):
            dp[0][i] = min(dp[0][i-1], prices[i])
            dp[1][i] = prices[i] - dp[0][i]  # profit
            dp[2][i] = max(dp[2][i-1], dp[1][i])
        return dp[2][n-1]
