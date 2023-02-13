class Solution:
    def maxProfit(self, prices):
        profit = 0
        min = prices[0]
        for i in range(len(prices)):
            temp = prices[i] - min
            if (min > prices[i]):
                min = prices[i]
            if (temp > profit):
                profit = temp
        return profit

        # time exceeded :
        # profit = 0
        # for i in range(len(prices)): 
        #     for sell_price in prices[i+1:]:
        #         buy_price = prices[i]
        #         temp = sell_price - buy_price
        #         if (temp > profit):
        #             profit = temp
        # return profit


# if __name__ == '__main__':
#     S = Solution()
#     prices = [7,1,5,3,6,4]
#     print(S.maxProfit(prices))
