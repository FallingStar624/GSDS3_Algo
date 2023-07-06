# N과 M(8)
# N과 M (4) 과 같은데
# 다만 숫자가 1,2,3,.. 이 아니고 주어지는 숫자.

import sys
n, m = map(int, sys.stdin.readline().split())
arrin = list(map(int, sys.stdin.readline().split()))
arr = [0 for _ in range(10)]

def func(k:int, idx: int) -> None:
    if (k==m):
        for i in range(m):
            print(arr[i], end = ' ')
        print()
        return
    for i in range(idx, n):
        arr[k] = arrin[i]
        func(k+1, i)

arrin.sort()
func(0, 0)