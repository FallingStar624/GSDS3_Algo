from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:


        if len(nums) <= 1:
            return nums
        
        n_dict = {}

        for idx, n in enumerate(nums):


            if n not in n_dict:
                nums[n] = idx
            




        return

if __name__ == '__main__':
    sol = Solution()
    nums = [2,7,11,15]
    target = 9

    print(sol.twoSum(nums, target))