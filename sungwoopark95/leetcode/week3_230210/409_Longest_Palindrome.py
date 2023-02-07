class Solution:
    def longestPalindrome(self, s: str) -> int:
        chardict = dict()
        for char in s:
            if char not in chardict:
                chardict[char] = 1
            else:
                chardict[char] += 1
        
        maxlen = 0
        for char in s:
            val = 2 * (chardict[char]//2)
            maxlen += val
            chardict[char] -= val
        
        if 1 in chardict.values():
            maxlen += 1

        return maxlen
