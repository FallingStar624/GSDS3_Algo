from typing import List


class Solution:
    def __init__(self):
        self.nums = []
        self.ans = -1
        self.target = -100000

    def bsearch(self, start, end):
        mid = (start+end)//2
        if start == end:
            if self.nums[start] == self.target:
                self.ans = start
            else:
                return
        else:
            self.bsearch(start, mid)
            self.bsearch(mid+1, end)

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        self.nums = nums
        self.target = target
        self.bsearch(0, n-1)
        return self.ans



