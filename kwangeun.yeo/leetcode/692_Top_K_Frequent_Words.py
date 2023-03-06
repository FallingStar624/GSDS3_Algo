class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = {}
        for word in words:
            if word in d:
                d[word] += 1
            else:
                d[word] = 1
        return [k for k, _ in sorted(d.items(), key=lambda x: (-x[1], x[0]))][:k]