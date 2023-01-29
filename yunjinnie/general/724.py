class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        # pivot = 0
        # maxlen = len(nums)
        # while (True):
        #     sum1 = 0
        #     sum2 = 0
        #     for i in range(maxlen):
        #         if(i<pivot):
        #             sum1 += nums[i]
        #         elif(i>pivot):
        #             sum2 += nums[i]
        #     if (sum1==sum2): break
        #     pivot +=1
        #     if (pivot == maxlen): return -1
        # return pivot
        for i, n in enumerate(nums):
            sum1 = sum(nums[:i])
            sum2 = sum(nums[i+1:])

            if (sum1 == sum2):
                return i
        return -1