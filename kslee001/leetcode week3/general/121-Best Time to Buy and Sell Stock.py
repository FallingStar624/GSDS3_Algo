from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        스택 문제
        0. 스택 비어있으면 current price 스택에 추가
        1. [ current price > top of the stack ] 인 경우, 스택을 비우고 현재 보고 있는 price를 top으로 만듦
            - ex. [4,6,1] 인 경우, 4에서 파는것보다 6에서 파는것이 무조건 이득이기 때문에 앞에 놈들 볼 필요가 없음
        2. [ current price <= top of the stack ] 인 경우, stack에 current price append 하고,
            top - current price (profit) 을 지금까지 기록한 max profit과 비교하며 업데이트
        3. iteration 끝나면 max profit 반환    
        """
        max_profit = 0 # target

        profit = [] #   
        idx = -1 # stack pointer 
        for cur in reversed(prices): # price
            """0. 스택 비었니?"""
            if len(profit) == 0:
                profit.append(cur) # push
                idx += 1
                continue

            top = profit[idx]
            """1. cur(지금 들어온 애)가 top보다 커?"""
            if cur > top:
                """그러면 스택 비우고 cur를 top으로 만들어"""
                while (idx >=0):
                    profit.pop()
                    idx -=1
                profit.append(cur)
                continue
                
            """2. cur가 top보다 작거나 같아?"""
            if cur <= top:
                """그러면 cur를 stack에 append하고 수익 비교해봐"""
                cur_profit = top-cur
                """만약 이게 최고 수익이면 기록 경신해"""
                if cur_profit > max_profit:
                    max_profit = cur_profit

        """3. iteration 끝나면 반환"""
        return max_profit