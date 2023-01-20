class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        cumsum = 0
        ans = []
        for num in nums:
            cumsum += num
            ans.append(cumsum)
        return ans