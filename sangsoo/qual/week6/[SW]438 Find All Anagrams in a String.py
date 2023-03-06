# 438. Find All Anagrams in a String
# solved but slow(하위 12.34%) , just change dictionary to Counter
from collections import Counter
from typing import List
class Solution:
    
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ls, lp = len(s), len(p)
        if lp > ls: return []
        p_dict = Counter(p)    
        output = []
        for i in range(ls-lp+1):
            slicing = s[i: i+lp]
            if (Counter(slicing) == p_dict):
                output.append(i)
        return output