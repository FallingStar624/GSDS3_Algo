class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left_sum = 0
        left_sums = []
        for num in nums:
            left_sums.append(left_sum)
            left_sum += num
        total_sum = left_sum
        for i, (num, left_sum) in enumerate(zip(nums, left_sums)):
            if left_sum == (total_sum - num) / 2:
                return i
        return -1