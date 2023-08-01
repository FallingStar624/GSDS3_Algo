import sys
import heapq

input = sys.stdin.readline
n = int(input())
heap = []
for i in range(n):
    nums = list(map(int, input().split()))
    for num in nums:
        heapq.heappush(heap, num)
        if(n < len(heap)): heapq.heappop(heap)
print(heapq.heappop(heap))