class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
      for i in range(len(nums)):
        left = sum(nums[:i])
        right = sum(nums[i+1:])
        if left == right:
          return i
      return -1


