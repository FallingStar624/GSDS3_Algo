from collections import Counter

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        ans = k
        for i in range(n, k, -1):
            for ws in range(0, n-i+1):
                tmp = Counter(s[ws:ws+i])
                if len(tmp)<1:
                    continue
                c = tmp.most_common(1)[0][1]
                if i-c <= k:
                    ans = max(i, ans)
        return ans
                
