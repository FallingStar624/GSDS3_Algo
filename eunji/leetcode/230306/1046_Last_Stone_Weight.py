from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 1:
           return stones[0]
        elif len(stones) == 0:
           return 0
        
        while len(stones) > 1:
          stones = sorted(stones)
          first = stones[-1] # 7
          second = stones[-2] # 3
          if first == second:
            stones.pop()
            stones.pop()

          else:
            stones[-1] = first - second # 4
            del stones[-2]

        if len(stones) == 1:
           return stones[0]
        else:
           return 0

 
if __name__ == '__main__':
    S = Solution()
    graph = [3,7,2]
    A = S.lastStoneWeight(graph)
    print(A)
            