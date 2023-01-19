from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ans = []
        tmp = 0
        for num in nums:
            tmp += num
            ans.append(tmp)
        return ans
            


