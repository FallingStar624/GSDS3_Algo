from typing import List

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

def isBadVersion(version: int) -> bool:
    bad = 4
    return bad <= version

class Solution:

    def firstBadVersion(self, n: int) -> int:

        return self.__helper(0, n)
    
    def __helper(self, start, end):

        if start == end:
            return end

        mid = start + int((end - start)/2)

        if isBadVersion(mid):
            return self.__helper(start, mid)
        else:
            return self.__helper(mid + 1, end)


if __name__ == '__main__':

    sol = Solution()
    n = 5
    
    sl = sol.firstBadVersion(n)
    print(sl)


