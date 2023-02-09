class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        out = [0]*len(nums)
        out[0] = nums[0]
        for i in range(1, len(nums)):
            out[i] = out[i-1] + nums[i]
        return out