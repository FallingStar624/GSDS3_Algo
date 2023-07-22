import sys
import heapq
T = int(sys.stdin.readline())
for _ in range(T):
    k = int(sys.stdin.readline())
    visited = [False for _ in range(k)] # 삭제 되었는지 확인
    minheap, maxheap = [], []
    for i in range(k):
        c, n = sys.stdin.readline().split(); n = int(n)
        if c == 'I':
            heapq.heappush(minheap, (n, i))
            heapq.heappush(maxheap, (-n, i))
            visited[i] = True
        else: # c == 'D'
            if n == 1:
                while maxheap and not visited[maxheap[0][1]]: # False : 삭제 되었거나, insert가 아니거나 찾을때 까지 pop
                    heapq.heappop(maxheap)
                if maxheap:
                    visited[maxheap[0][1]] = False
                    heapq.heappop(maxheap)
            else: # n == -1
                while minheap and not visited[minheap[0][1]]:
                    heapq.heappop(minheap)
                if minheap:
                    visited[minheap[0][1]] = False
                    heapq.heappop(minheap)
    while minheap and not visited[minheap[0][1]]:
        heapq.heappop(minheap)
    while maxheap and not visited[maxheap[0][1]]:
        heapq.heappop(maxheap)
    print(-maxheap[0][0], minheap[0][0]) if maxheap and minheap else print("EMPTY")