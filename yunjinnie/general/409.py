class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        lst = []
        for i in range(len(s)):
            if s[i] in lst:
                ans+=2
                lst.pop(lst.index(s[i]))
            else:
                lst.append(s[i])
        if len(lst)>0:
            ans+=1

        return ans