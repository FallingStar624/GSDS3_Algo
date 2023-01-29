from typing import *

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        checklist = [char for char in s]
        idx = 0
        if len(checklist)== 0:
            return True
        for char in t:
            cur_check = checklist[idx]
            if char == cur_check:
                idx +=1
            if idx == len(s):
                return True
        return False