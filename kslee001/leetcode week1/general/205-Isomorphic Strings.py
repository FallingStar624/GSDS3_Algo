from typing import *

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_encode = dict()
        t_encode = dict()
        s_idx = 0
        t_idx = 0
        for char1, char2 in zip(s, t):
            if char1 not in s_encode:
                s_encode[char1] = s_idx
                s_idx +=1
            if char2 not in t_encode:
                t_encode[char2] = t_idx
                t_idx +=1
        s_decode = [s_encode[char] for char in s]
        t_decode = [t_encode[char] for char in t]
        return s_decode == t_decode
        