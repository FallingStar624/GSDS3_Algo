import heapq
import sys

input = sys.stdin.readline

n = int(input())
d = {}
minheap, maxheap = [], []
deleted = set()

for i in range(n):
    p, l = map(int, input().split()) # p : 문제번호 l : 난이도
    d[p] = l
    heapq.heappush(minheap, (l, p)) # 난이도, 문제번호
    heapq.heappush(maxheap, (-l, -p)) #난이도 내림차순 정렬 -> 문제번호 내림차순 정렬

m = int(input())

for i in range(m):
    op = list(input().split())
    if op[0] == "add":
        op[1], op[2] = int(op[1]), int(op[2])
        while minheap[0][1] in deleted:
            heapq.heappop(minheap)
        while -maxheap[0][1] in deleted:
            heapq.heappop(maxheap)
        if op[1] in deleted: deleted.remove(op[1]) # 같은 문제번호가 여러번 들어올 수 있음!!
        d[op[1]] = op[2]
        heapq.heappush(minheap, (op[2], op[1]))
        heapq.heappush(maxheap, (-op[2], -op[1]))
    elif op[0] == "recommend":
        op[1] = int(op[1])
        if op[1] == 1:
            while -maxheap[0][1] in deleted:
                heapq.heappop(maxheap)
            print(-maxheap[0][1])
        elif op[1] == -1:
            while minheap[0][1] in deleted:
                heapq.heappop(minheap)
            print(minheap[0][1])

    else:  # solved 
        deleted.add(int(op[1]))

