import sys
n, m = map(int, sys.stdin.readline().split())

arr = [0 for _ in range(10)]
isused = [0 for _ in range(10)]

def func(k:int)->None:
    if k == m:
        for i in range(m):
            print(arr[i], end = ' ')
        print()
        return
    
    for i in range(1, n+1):
        if (not isused[i]):
            arr[k] = i
            isused[i] = 1
            func(k+1)
            isused[i] = 0

func(0)