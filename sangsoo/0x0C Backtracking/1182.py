import sys
n, s = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

summ = 0
cnt = 0
def func(k:int)->None:
    global cnt, summ
    if (summ == s and k>0):
        cnt += 1
    for i in range(k, n):
        summ += arr[i]
        func(i+1)
        summ -= arr[i]
func(0)
print(cnt)
