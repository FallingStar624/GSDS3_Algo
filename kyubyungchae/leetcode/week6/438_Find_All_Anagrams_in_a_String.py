from typing import List
from collections import Counter

class Solution:

    def findAnagrams(self, s: str, p: str) -> List[int]:

        output = []
        p_len = len(p)
        s_len = len(s)

        if p_len > s_len:
            return output

        map_p = Counter(p)

        window = None
        for i in range(s_len - p_len + 1):
            if i == 0:
                window = Counter(s[:p_len])
            else:
                window[s[i-1]] -= 1
                window[s[i+p_len-1]] += 1

            if len(window - map_p) == 0:
                output.append(i)
        
        return output



    def _findAnagrams(self, s: str, p: str) -> List[int]:

        output = []
        for idx in range(len(s)):
            
            tmp = s[idx:idx + len(p)]
            if len(tmp) < len(p):
                continue
            
            if sorted(tmp) == sorted(p):
                output.append(idx)

        return output
    



if __name__ == '__main__':
    sol = Solution()
    s = "cbaebabacd"
    p = "abc"
    print(sol.findAnagrams(s, p))