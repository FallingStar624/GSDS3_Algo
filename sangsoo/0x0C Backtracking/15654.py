import sys
n, m = map(int, sys.stdin.readline().split())
arrin = list(map(int, sys.stdin.readline().split()))
isused = [False for _ in range(10001)]
arr = [0 for _ in range(10)]

def func(k:int)->None:
    if(k == m):
        for i in range(m):
            print(arr[i], end =' ')
        print()
        return
    for i in range(n):
        if(not isused[arrin[i]]):
            arr[k] = arrin[i]
            isused[arrin[i]] = 1
            func(k+1);
            isused[arrin[i]] = 0

arrin.sort()
func(0)

