# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        start = 1
        end = n 
        while True:
            middle = (start + end) //2
            if (middle == 1 and isBadVersion(middle) == True):
                return middle
            if (isBadVersion(middle) == True):
                if  isBadVersion(middle-1) == False:
                    return middle
                end = middle - 1
            elif (isBadVersion(middle) == False):
                start = middle + 1
