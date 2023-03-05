from collections import deque


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s1, s2 = deque(), deque()
        for ss in s:
            if ss >= 'a':
                s1.append(ss)
            else:
                if s1:
                    s1.pop()
        for tt in t:
            if tt >= 'a':
                s2.append(tt)
            else:
                if s2:
                    s2.pop()
        if len(s1) != len(s2):
            return False
        for ss, tt in zip(s1, s2):
            if ss == tt:
                continue
            else:
                return False
        return True




