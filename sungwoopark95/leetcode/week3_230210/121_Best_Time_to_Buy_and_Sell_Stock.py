from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        buy_index = 0
        sell_index = 1

        while sell_index < len(prices):
            curr_profit = prices[sell_index] - prices[buy_index]
            if curr_profit < 0:
                buy_index = sell_index
            else:
                max_profit = max(curr_profit, max_profit)
            sell_index += 1
        
        return max_profit
