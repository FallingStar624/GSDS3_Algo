class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # mapping -> 1:1? hash
        # or replacing?
        # egg 011 add 011
        # foo 011 bar 012
        # bbbaaaba 00011101 aaabbbba 00011110
        sh = {}
        sl = []
        th = {}
        tl = []
        idxs = 0
        idxt = 0

        for i in range(len(s)):
            if (s[i] in sh.keys()):
                #idx -=1
                sl.append(sh[s[i]])
                #idx +=1
            if (t[i] in th.keys()):
                tl.append(th[t[i]])
            if (s[i] not in sh.keys()): # else
                sh[s[i]] = idxs
                sl.append(idxs)
                idxs +=1
            if (t[i] not in th.keys()):
                th[t[i]] = idxt
                tl.append(idxt)
                idxt +=1
            #print(sl)
            #print(tl)
            
        if (sl == tl):
            return True

        return False