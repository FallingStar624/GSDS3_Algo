from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        answer = []
        for i in range(len(nums)):
            answer.append(sum(nums[:i+1]))
        return answer