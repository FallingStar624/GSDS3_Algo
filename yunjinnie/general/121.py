class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # maximum profit = max (later) - min (early)
        ans = 0
        st = prices[0]
        
        for i, p in enumerate(prices):
            # i = index, p = element
            # if prices[i]<max(st):
            if p<st:
                st = p
                # day = st.pop()
            elif p - st > ans:
                ans = p - st
            # st.append(i) # index
        # print(st)

        return ans

#https://rollingsnowball.tistory.com/124