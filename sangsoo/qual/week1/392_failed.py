# falied
# 18개 중에 17번째 test case에서 막힘
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if(len(s) == 1 and len(t) == 1 and s != t):
            return False
        dic_t = dict.fromkeys(t)
        for i, ch in enumerate(t):
            dic_t[ch] = i
        for i in range(1, len(s)):
            if s[i] not in dic_t:
                return False
            if(dic_t[s[i-1]] >= dic_t[s[i]]):
                return False
        return True