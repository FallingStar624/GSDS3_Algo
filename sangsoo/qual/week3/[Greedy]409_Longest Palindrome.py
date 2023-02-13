#409. Longest Palindrome
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # initialize
        lendict = dict.fromkeys(s, 0)
        # save the number of each letter
        for ch in s:
            lendict[ch] += 1
        # check if odd or even
        keys = list(lendict.keys())
        result = 0
        odd_cnt = 0
        for k in keys:
            if lendict[k] % 2 == 0:
                result += lendict[k]
            else:
                odd_cnt += 1
                result += lendict[k]-1
        if odd_cnt > 0:
            result += 1
        return result
