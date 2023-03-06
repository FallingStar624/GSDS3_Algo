from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ans = []
        if words == None:
           return ans
        wordsNum = Counter(words)
        wordsNum_K = dict()
        for w, num in wordsNum.items():
            if num in wordsNum_K:
              wordsNum_K[num].extend([w])
            else:
              wordsNum_K[num] = [w]
        for i in sorted(wordsNum_K, reverse=-1):
           ans.extend(sorted(wordsNum_K[i]))
        return ans[:k]

                
if __name__ == '__main__':
    S = Solution()
    graph = ["i","love","leetcode","i","love","coding"]
    k = 3
    A = S.topKFrequent(graph,k)
    print(A)
            
            