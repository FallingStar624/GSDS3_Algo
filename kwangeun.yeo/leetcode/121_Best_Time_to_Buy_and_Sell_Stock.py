# O(N^2) solution -> 10^10, impossible
# class Solution:
#     def maxProfit(self, prices: List[int]) -> int:
#         max_profit = 0
#         for i in range(len(prices) - 1):
#             for j in range(i + 1, len(prices)):
#                 max_profit = max(max_profit, prices[j] - prices[i])
#         return max_profit

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        max_profit = 0
        for price in prices:
            if price < buy:
                buy = price
            else:
                profit = price - buy
                max_profit = max(profit, max_profit)
        return max_profit