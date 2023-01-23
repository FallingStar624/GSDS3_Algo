from typing import List

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        iso_map = {}

        for left, right in zip(s, t):
            
            if left in iso_map.keys():
                if iso_map[left] != right:
                    return False
            elif right in iso_map.values():
                return False
            else:
                iso_map[left] = right

        return True


if __name__ == '__main__':

    sol = Solution()
    # s = "egg"; t = "add"
    s = "badc"; t = "baba"

    sl = sol.isIsomorphic(s, t)
    print(sl)