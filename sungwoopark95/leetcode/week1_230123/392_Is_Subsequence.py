class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        i = 0
        s_stack = [s[i]]
        for c in t:
            if c in s_stack:
                s_stack.pop()
                if i < len(s) - 1:
                    i += 1
                    s_stack.append(s[i])
        
        if s_stack:
            return False
        return True