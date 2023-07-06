# N과 M(3)
# N개 중에서 M 개뽑는데, 중복 허용(복원추출 개념)해서 뽑기
import sys
n, m = map(int, sys.stdin.readline().split())
arr = [0 for _ in range(8)]

def func(k:int) -> None:
    if (k == m):
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return
    for i in range(1, n+1):
        arr[k] = i
        func(k+1)
func(0)