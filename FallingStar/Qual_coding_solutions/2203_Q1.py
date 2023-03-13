# 2022_03_Qualification_Exam Q1
from typing import List


def palindromes(s) -> bool:
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            return False
    return True


def substring(s, t) -> bool:
    m = len(s)
    n = len(t)
    if m < n:
        return False
    for i in range(m-n+1):
        if s[i:i+n] == t:
            return True
    return False


def max_palindromes(s) -> List[str]:
    p_list = []
    n = len(s)
    for i in range(n):
        for j in range(i+1, n+1):
            if palindromes(s[i:j]):
                p_list.append(s[i:j])
    m = len(p_list)
    sub = [False for _ in range(m)]
    for i in range(m):
        for j in range(m):
            if i != j and not sub[i]:
                sub[i] = substring(p_list[j], p_list[i]) or sub[i]
    ans = []
    for idx, p in enumerate(p_list):
        if not sub[idx]:
            ans.append(p)
    return ans


if __name__ == "__main__":
    aaa = "kabccbadzdefgfeda"
    print(max_palindromes(aaa))
    bbb = "kabccba dzabccbaza"
    print(max_palindromes(bbb))




