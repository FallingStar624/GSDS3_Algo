from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for pivot in range(len(nums)):
            if pivot == 0:
                leftsum = 0
            else:
                leftsum = sum(nums[:pivot])
            
            rightsum = sum(nums[pivot+1:])
            if leftsum == rightsum:
                return pivot

        return -1