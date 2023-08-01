import heapq
import sys
input = sys.stdin.readline

n = int(input())
heap = []
for _ in range(n):
    x = int(input())
    heapq.heappush(heap, x)
sum = 0
while(len(heap)>1):
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    sum += (a + b)
    heapq.heappush(heap, a + b)

print(sum)
