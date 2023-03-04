class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        ans = [0 for _ in range(len(cost)+1)]
        ans[1] = cost[0]
        ans[2] = cost[1]

        for i in range(3, len(ans)):
            ans[i] = min(ans[i-2], ans[i-1]) + cost[i-1]

        return ans[-1]
