class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_dict = {}
        for c in p:
            if c in p_dict:
                p_dict[c] += 1
            else:
                p_dict[c] = 1
        s_dict = {k:0 for k in p_dict.keys()}
        ret = []
        for i in range(len(s) - len(p) + 1):
            if i == 0:
                for c in s[:len(p)]:
                    if c in s_dict:
                        s_dict[c] += 1
            else:
                old = s[i - 1]
                new = s[i + len(p) - 1]
                if old in s_dict:
                    s_dict[old] -= 1
                if new in s_dict:
                    s_dict[new] += 1
            if s_dict == p_dict:
                ret.append(i)
        return ret