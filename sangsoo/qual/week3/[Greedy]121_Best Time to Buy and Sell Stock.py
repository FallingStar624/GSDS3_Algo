#121. Best Time to Buy and Sell Stock
from typing import List 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        minprice = prices[0]
        for i in range(1, len(prices)):
            if prices[i] > minprice:
                if profit < prices[i] - minprice:
                    profit = prices[i] - minprice
            if prices[i] < minprice:
                minprice = prices[i]
        return profit
            