import heapq
import sys
input = sys.stdin.readline
n = int(input())
d = {}
minheap, maxheap = [], []
for i in range(n):
    p, l = map(int, input().split()) # p : 문제번호 l : 난이도
    d[p] = l
    heapq.heappush(minheap, (l, p)) # 난이도, 문제번호
    heapq.heappush(maxheap, (-l, p))

m = int(input())
for i in range(m):
    op = list(input().split())
    if op[0] == "add":
        op[1] = int(op[1]); op[2] = int(op[2])
        d[op[1]] = op[2]
        heapq.heappush(minheap, (op[2], op[1]))
        heapq.heappush(maxheap, (-op[2], op[1]))
    elif op[0] == "recommend":
        op[1] = int(op[1])
        if op[1] == 1:
            print(maxheap[0][1])
        else:
            print(minheap[0][1])
    else: # solved
        op[1] = int(op[1])
        l, p = d[op[1]], op[1]
        d.pop(op[1])
        minheap.remove((l, p))
        maxheap.remove((-l, p))
        heapq.heapify(minheap)
        heapq.heapify(maxheap)
    

