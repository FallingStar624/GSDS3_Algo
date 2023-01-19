from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            left = sum(nums[:i])
            print(left)
            right = sum(nums[i+1:])
            print(right)
            if left == right:
                return i
        return -1
