class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        chk = 0
        for t_word in t:
            if t_word == s[chk]:
                chk += 1
                if chk == len(s):
                    return True
        if chk == len(s):
            return True
        return False        
            