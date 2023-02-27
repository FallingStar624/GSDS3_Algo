from collections import Counter 

class Solution:
    def findAnagrams(self, s, p):
        ans = []
        sst = list(s)
        pst = list(p)
        anag_label = Counter(p)
            
        for i in range(len(sst)-len(pst)+1):
            if Counter(s[i:i+len(pst)]) == anag_label:
                ans.append(i)
        return ans
    
