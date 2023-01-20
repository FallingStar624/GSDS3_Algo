class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapper = {}
        mapped = set()
        for src, trg in zip(s, t):
            if src in mapper:
                if mapper[src] != trg:
                    return False
            elif trg not in mapped:
                mapper[src] = trg
                mapped.add(trg)
            else:
                return False
        return True