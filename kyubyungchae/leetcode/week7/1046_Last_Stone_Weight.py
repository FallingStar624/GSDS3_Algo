from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        while len(stones) > 1:
            
            x, y = (0, 0), (0, 0)
            for idx, st in enumerate(stones):

                if st > y[1]:
                    x = y
                    y = (idx, st)
                elif st > x[1]:
                    x = (idx, st)

            if x[1] == y[1]:
                stones.pop(x[0])
                stones.pop(y[0])
            else:
                stones[y[0]] = y[1] - x[1]
                stones.pop(x[0])

        if len(stones) == 0:
            return 0

        return stones[0]
    

if __name__ == '__main__':
    sol = Solution()

    stones = [2,2]
    print(sol.lastStoneWeight(stones))