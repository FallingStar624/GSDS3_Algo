class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        h = [0 for _ in range(len(s))]
        for i in range(len(s)-1, -1, -1):
            for j in range(len(p)):
                if i>=j:
                    h[i-j] += hash(s[i])
        tgt = 0
        for c in p:
            tgt += hash(c)
        for i in range(len(s)):
            if h[i] == tgt:
                ans.append(i)
        return ans
