from typing import List


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        first = list(s)
        second = list(t)
        first_unique = []
        second_unique = []
        for char1, char2 in zip(s, t):
            if char1 not in first_unique:
                first_unique.append(char1)
            if char2 not in second_unique:
                second_unique.append(char2)
        for i in range(len(s)):
            first[i] = first_unique.index(first[i])
            second[i] = second_unique.index(second[i])
        if first == second:
            return True
        else:
            return False




