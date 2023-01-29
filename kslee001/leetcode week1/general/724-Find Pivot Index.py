from typing import *

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        start = 0
        end = len(nums)
        for idx in range(len(nums)):
            mid = idx
            L = nums[start:mid]
            R = nums[mid+1:end]
            if(sum(L) == sum(R)):
                return mid
        return -1
