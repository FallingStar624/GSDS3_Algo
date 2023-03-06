class Solution:
    def minCostClimbingStairs(self, cost):
      dp = [cost[0], cost[1]]
      length = len(cost)
      for i in range(2, length):
        new = min(dp[i-1], dp[i-2]) + cost[i]
        dp.append(new)
      # print(dp)
      return min(dp[length-1], dp[length-2])