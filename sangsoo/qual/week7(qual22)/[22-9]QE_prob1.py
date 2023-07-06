from typing import List
def toString(List):
    return ''.join(List)

def str_perm(s: str) -> List:
    result = []
    def str_perm_help(a, l, r):
        # print(f"a: {a}, l: {l}, r: {r}")
        if l == r:
            result.append(toString(a))
        else:
            for i in range(l, r + 1):
                # print(f"i: {i}, l: {l}, r: {r}")
                a[l], a[i] = a[i], a[l]
                str_perm_help(a, l + 1, r)
                # backtrack
                a[l], a[i] = a[i], a[l]
    list_s = list(s)
    str_perm_help(list_s, 0, len(s)-1)
    return result