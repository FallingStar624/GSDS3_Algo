from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:

        w_map = Counter(words)
        # print(w_map)
        w_map = sorted(w_map.items(), key=lambda x: (-x[1], x[0])) # x[0]: alphabet   # x[1]: # (x[0], -x[1])
        # print(w_map)

        return [w[0] for w in w_map[:k]]
    

if __name__ == '__main__':
    sol = Solution()
    
    words = ["i","love","leetcode","i","love","coding"];k = 3
    print(sol.topKFrequent(words, k))