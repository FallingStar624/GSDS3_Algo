# heapq.heappush(heap, (abs(n), n)) # (우선순위, 값)
import sys
import heapq
input = sys.stdin.readline
heap = []

n = int(input())
for _ in range(n):
    x = int(input())
    if (x!=0):
        heapq.heappush(heap, (abs(x), x))
    else:
        if (heap):
            print(heapq.heappop(heap)[1])
        else:
            print(0)