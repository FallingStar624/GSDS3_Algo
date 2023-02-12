#704. Binary Search (Binary Search)
'''
[Algorithm]
(문제요구사항) binary search로 target을 찾아서 index를 리턴해라. 
1. 반으로 나누면서 찾는다. 
  - 이때 DFS를 쓰면 어렵다. 왜냐하면 index를 리턴해야하는데 index값이 바뀌기 때문이다.
2. left 와 right를 정하고 
3. nums[mid] == target이면 return mid
4. nums[mid] < target 또는 nums[mid] > target이면, 
    left = mid+1, right = mid-1 로 assign한다.
    while의 조건은 (left <= right) 으로 한다. 
'''
from typing import List
class Solution:
    def search(self, nums:List[int], target: int)->int:
        # Set the left and right boundaries
        left = 0
        right = len(nums) -1

        # Under this condition
        while left <= right:
            # Get the middle index and the middle value
            mid = (left + right) // 2
            # Case 1. return the middle index
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        # if we finish the search without finding target, return -1
        return -1
