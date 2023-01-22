class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping1 = dict()
        mapping2 = dict()
        for c_s, c_t in zip(s, t):
            mapping1[c_s] = c_t
            mapping2[c_t] = c_s
        
        compare1 = ""
        compare2 = ""
        for c_s, c_t in zip(s, t):
            compare1 += mapping1[c_s]
            compare2 += mapping2[c_t]

        if compare1 == t and compare2 == s:
            return True
        return False