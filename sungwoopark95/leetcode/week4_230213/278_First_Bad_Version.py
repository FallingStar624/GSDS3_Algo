# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return self.searchHelp(start=1, end=n)

    def searchHelp(self, start, end):
        ans = (2**32)
        while start <= end:
            mid = (start + end) // 2
            if isBadVersion(mid):
                if ans > mid:
                    ans = mid
                # 첫 번째 bad version이 아닐 수 있으므로 더 작은 값을 search
                end = mid - 1
            else:
                # 아직 bad version이 나오지 않았으므로 더 큰 값을 search
                start = mid + 1
        return ans
