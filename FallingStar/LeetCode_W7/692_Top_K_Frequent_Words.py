from typing import List
from collections import Counter
from heapq import heapify

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = Counter(words)
        top_k = []
        for key, value in c.items():
            top_k.append((value, key))
        heapify(top_k)
        top_k.sort(key=lambda x: (-x[0], x[1]))
        ans = [x[1] for x in top_k]
        return ans[:k]

