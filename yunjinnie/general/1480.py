class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        lst = []
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            lst.append(sum)
        return lst