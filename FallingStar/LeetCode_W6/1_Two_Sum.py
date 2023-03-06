from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dd = defaultdict(list)
        for idx, num in enumerate(nums):
            dd[str(num)].append(idx)
        for idx, num in enumerate(nums):
            counterpart = target-num
            if str(counterpart) in dd.keys():
                if counterpart*2 == target:
                    if len(dd[str(num)])>1:
                        c_idx = dd[str(num)][1]
                    else:
                        continue
                else:
                    c_idx = dd[str(counterpart)][0]
                return [idx, c_idx]
            

