

class Solution:
    def __init__(self):
        self.a = 0

    def bsearch(self, s, e):
        m = (s+e)//2
        if s > e:
            return
        if isBadVersion(m):
            self.a = min(self.a, m)
            self.bsearch(s, m-1)
        else:
            self.bsearch(m+1, e)

    def firstBadVersion(self, n: int) -> int:
        self.a = n
        self.bsearch(1, n)
        return self.a

