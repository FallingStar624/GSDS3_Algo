# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        # 중간값부터 위아래로 증가시켜나가면서 call
        st = 1
        en = n
        
        def binary(left, right):
            mid = left+(right-left)//2
            if left<=right:
                #if mid>=right:
                if isBadVersion(mid): # true -> lower
                    return binary(left, mid-1)
                else: # false -> upper
                    return binary(mid+1, right)
            else:
                return left
            
        ans = binary(st, en)
        
        # while

# https://velog.io/@heejun32/leetcode-278.-First-Bad-Version-Python