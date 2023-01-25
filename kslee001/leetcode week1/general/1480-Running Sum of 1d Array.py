from typing import *

class Solution:
    def __init__(self):
        None
    
    def runningSum(self, nums:List[int])-> List[int]:
        R = []
        cur = 0
        for idx in range(len(nums)):
            cur += nums[idx]
            R.append(cur)
        return R