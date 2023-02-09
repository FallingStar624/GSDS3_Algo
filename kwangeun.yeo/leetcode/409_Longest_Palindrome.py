class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        odd = [v for v in d.values() if v % 2 == 1]
        even = [v for v in d.values() if v % 2 == 0]
        return sum(odd) - len(odd) + sum(even) + (1 if odd else 0)