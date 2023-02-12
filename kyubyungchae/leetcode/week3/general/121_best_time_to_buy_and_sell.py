from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        idx = 0
        prev =  100001
        for i, p in enumerate(prices):
            # print(prev, p)
            profit = p - prev            

            if profit > max_profit:
                idx = i
                max_profit = profit

            if p < prev:
                prev = p

        return max_profit


if __name__ == '__main__':
    sol = Solution()
    prices = [7,1,5,3,6,4]
    s = sol.maxProfit(prices)
    print(s)