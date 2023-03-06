class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def calculate_pay(idx, p):
            next_idx = lambda x : x+1 if cost[x+1] < cost[x+2] else x+2
            
            while idx < n:
                if idx +2 >= n:
                    return p
                idx = next_idx(idx)
                p += cost[idx]    
            return p
        n = len(cost)
        p1 = cost[0]
        p_idx1 = 0
        p2 = cost[1]
        p_idx2 = 1

        p1 = calculate_pay(p_idx1, p1)
        p2 = calculate_pay(p_idx2, p2)
        res = min(p1, p2)
        if n == 4:
            res = min(cost[0]+cost[2], res)
        return res