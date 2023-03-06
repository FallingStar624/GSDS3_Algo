from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:

        if not nums:
            return -1
        
        return self.__helper(nums, 0, len(nums), target)

    def __helper(self, nums, start, end, target):

        if start == end:
            return -1
        
        mid = start + (end - start)//2        

        if nums[mid] == target:
            return mid

        if nums[mid] > target:
            return self.__helper(nums, start, mid, target)
        else:
            return self.__helper(nums, mid+1, end, target)



if __name__ == '__main__':
    nums = [-1,0,3,5,9,12]
    target = 2

    sol = Solution()
    sl = sol.search(nums, target)
    print(sl)