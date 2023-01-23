class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
      ans = []  # 1 2 3 4
      count = 0
      for i in nums: # 1 2 3
        count += i # 1 3 6
        ans.append(count)
      return ans
