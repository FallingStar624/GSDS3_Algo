# N과 M(4)
# N개 중에서 M 개뽑는데,
# M개 사이에는 중복허용 sample 간에는 중복 미허용
import sys
n, m = map(int, sys.stdin.readline().split())
arr = [0 for _ in range(10)]

def func(k: int) -> None:
    if(k==m):
        for i in range(m):
            print(arr[i], end = ' ')
        print()
        return
    st = 1
    if (k != 0): st = arr[k-1]
    for i in range(st, n+1):
        arr[k] = i
        func(k+1)

func(0)