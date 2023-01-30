from collections import Counter

class Solution:
    def longestPalindrome(self, s: str) -> int:
        words = Counter(s)
        odd = False
        ans = 0
        for value in words.values():
            if value % 2:
                odd = True
                ans += (value//2)*2
            else:
                ans += value
        ans += odd
        return ans
