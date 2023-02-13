from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        start = 0
        end = n
        
        while (start < end):
            mid = start + (end-start)//2
            # 중간값이 target보다 작은 경우 -> 오른쪽만 보기
            if nums[mid] < target:
                start = mid+1
            # 중간값이 target보다 큰 경우 -> 왼쪽만 보기
            elif nums[mid] > target:
                end = mid
            # target 발견한경우 -> return index
            else:
                return mid
        
        # 못 발견하면 return -1
        return -1