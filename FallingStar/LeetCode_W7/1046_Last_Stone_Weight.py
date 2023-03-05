from typing import List
from heapq import heapify, heappop, heappush

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        ans = [-x for x in stones]
        heapify(ans)
        while len(ans) > 1:
            top1 = heappop(ans)
            top2 = heappop(ans)
            tmp = abs(top1-top2) * (-1)
            if tmp == 0:
                continue
            else:
                heappush(ans, tmp)
        if not ans:
            return 0
        return ans[0]*(-1)


