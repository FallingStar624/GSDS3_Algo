# 1. Two Sum
# solved but slow
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_subtract = [0 for i in range(len(nums))]
        out = []
        tmp = []
        for i in range(len(nums)):
            nums_subtract[i] = -nums[i] + target
        for i in range(len(nums)):
            tmp = nums[:]
            tmp.remove(nums[i])
            if nums_subtract[i] in tmp:
                out.append(i)
        return out