class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # hash
        # sh = {}
        # th = {}
        # sl = []
        # tl = []
        idxs = 0
        #idxt = 0

        # for i in range(len(s)):
        #     if (s[i] not in sh.keys()):
        #         sh[s[i]] = idxs
        #         sl.append(idxs)
        #         idxs +=1
        #     else:
        #         sl.append(sh[s[i]])

        # for i in range(len(t)):
        #     if (t[i] in sh.keys()):
        #         tl.append(sh[t[i]])                
        
        # if (sl == tl):
        #     return True
        # elif (sh.values not in tl):
        #     return False
        # else: return True

        if len(s) == 0:
            return True
            
        for i in t:
            if i == s[idxs]:
                idxs +=1
                if idxs == len(s):
                    return True

        return False