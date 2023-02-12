#278. First Bad Version (Binary Search)
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:
'''
[Algorithm]
(문제요구사항) binary search로 Badversion==True 중 가장빠른 index를 리턴해라. 
1. 반으로 나누면서 찾는다. 
2. left 와 right를 정하고 (left=1, right=n, 왜냐하면 문제 설정이 index가 1부터임(0부터가 아니고))
3. return left로 해야한다. 
   - mid로 하면 바뀌지 않고 while문이 종료되는 경우가 생긴다. 
4. right = mid-1로 하면 안되고 right = mid로 해야한다.
   - mid로 해야 해당지점부터 오른쪽으로 True이기 때문에 그부분까지 포함해서 다시 탐색해야한다.  
'''

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n
        mid = (left+right) // 2
        while left < right:
            mid = (left + right) // 2
            if isBadVersion(mid) == False:
                left = mid + 1
            else:
                right = mid 
        return left

