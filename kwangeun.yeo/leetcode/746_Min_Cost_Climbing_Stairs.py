class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        total = [0 for _ in range(len(cost))]
        total[0] = cost[0]
        total[1] = min(cost[0], cost[1])
        for i in range(len(cost)):
            total[i] = cost[i] + min(total[i - 1], total[i - 2]) 
        return total[-1]