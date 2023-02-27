class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_with_idx = [(i, n) for i, n in enumerate(nums)]
        nums_with_idx.sort(key=lambda x:x[1])
        i, j = 0, len(nums_with_idx) - 1
        while i <= j:
            twosum = nums_with_idx[i][1] + nums_with_idx[j][1]
            if twosum == target:
                return [nums_with_idx[i][0], nums_with_idx[j][0]]
            elif twosum < target:
                i += 1
            else:
                j -= 1