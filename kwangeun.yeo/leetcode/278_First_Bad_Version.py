# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return self.bs(1, n)
    
    def bs(self, s, e):
        if s > e:
            return -1
        m = (s + e) // 2
        if isBadVersion(m):
            l = self.bs(s, m - 1)
            return m if l == -1 else l
        else:
            return self.bs(m + 1, e)