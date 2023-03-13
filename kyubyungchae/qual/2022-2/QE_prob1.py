from typing import List


def permutations(iterable, r=None):

    result = []

    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))

    tmp = ''
    for i in indices[:r]:
        tmp += pool[i] 
    yield tmp

    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                tmp = ''
                for i in indices[:r]:
                    tmp += pool[i] 
                yield tmp
                break
        else:
            return

def str_perm(s: str) -> List:
    perm = list(permutations(s, len(s)))

    ans = []
    for p in perm:

        if p not in ans:
            ans.append(p)

    return ans

if __name__ == '__main__':

    # s = "kabccbadzdefgfeda"
    s = "abb"
    result = str_perm(s)
    print(result)
