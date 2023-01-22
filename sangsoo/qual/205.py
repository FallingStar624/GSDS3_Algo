class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic_s = dict.fromkeys(s)
        dic_t = dict.fromkeys(t)
        for c1, c2 in zip(s, t):
            if (dic_s[c1] == None):
                dic_s[c1] = c2
            elif(dic_s[c1] != c2):
                return False
            if (dic_t[c2] == None):
                dic_t[c2] = c1
            elif(dic_t[c2] != c1):
                return False

        return True
