from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        arr = []
        new_num = 0
        for n in nums:
            new_num = new_num + n
            arr.append(new_num)
        return arr