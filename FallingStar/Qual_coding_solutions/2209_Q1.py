# 2022_09_Qualification_Exam Q1
from typing import List
from itertools import permutations


def str_perm(s: str) -> List:
    n = len(s)
    ans = set()
    for p in permutations(s, n):
        p = "".join(p)
        ans.add(p)
    ans = sorted(list(ans))
    return ans


if __name__ == "__main__":
    a = "abb"
    print(str_perm(a))

