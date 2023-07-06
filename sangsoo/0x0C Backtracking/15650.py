# N과 M(2) combination
# N개중에서 M개 뽑기 중복 미허용(조합 Combination)
import sys
n, m = map(int, sys.stdin.readline().split())
arr = [0 for _ in range(10)]
isused = [0 for _ in range(10)]
st = 0
def func(k:int) -> None:
    global st
    if (k == m):
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return
    if k ==0 : st = 1
    else: st = arr[k-1]+1
    for i in range(st, n+1):
        if(not isused[i]):
            arr[k] = i
            isused[i] = 1
            func(k+1)
            isused[i] = 0

func(0)