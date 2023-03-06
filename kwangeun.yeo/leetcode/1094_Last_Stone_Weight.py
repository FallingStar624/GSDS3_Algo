class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones = sorted(stones)
            y = stones[-1]
            x = stones[-2]
            stones = stones[:-2]
            if x == y:
                continue
            else:
                stones.append(y - x)
        return 0 if not stones else stones[0]