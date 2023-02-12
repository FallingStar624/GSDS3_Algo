class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.bs(nums, 0, len(nums) - 1, target)
    
    def bs(self, nums, s, e, t):
        if s > e:
            return -1
        m = (s + e) // 2
        if nums[m] == t:
            return m
        elif nums[m] > t:
            return self.bs(nums, s, m - 1, t)
        elif nums[m] < t:
            return self.bs(nums, m + 1, e, t)