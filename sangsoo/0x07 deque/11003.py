import sys
from collections import deque
NL = sys.stdin.readline().split()
N, L = int(NL[0]), int(NL[1])

arr = sys.stdin.readline().split()
for i in range(len(arr)):
    arr[i] = int(arr[i])
dq = deque() # index를 저장
out = []
for i in range(N):
    while dq and dq[0] < i-L+1:
        dq.popleft()
    while dq and arr[dq[-1]] > arr[i]:
        dq.pop()
    dq.append(i)
    print(arr[dq[0]], end = ' ')
