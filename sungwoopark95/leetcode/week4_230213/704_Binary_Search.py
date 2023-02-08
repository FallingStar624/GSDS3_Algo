from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.searchHelp(nums, target, 0, len(nums)-1)

    def searchHelp(self, nums, target, start, end):
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        
        return -1
