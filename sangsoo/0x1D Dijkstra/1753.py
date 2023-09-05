import sys
import heapq
input = sys.stdin.readline

v, e = map(int, input().split())
st = int(input())
adj = [[] for _ in range(v+1)]
INF = float('inf')
d = [INF] * (v+1)

for _ in range(e):
    a, b, w = map(int, input().split())
    adj[a].append((w, b))

pq = []
d[st] = 0
heapq.heappush(pq, (d[st], st))

while pq:
    cur_cost, cur_vertex = heapq.heappop(pq)
    
    if d[cur_vertex] != cur_cost:
        continue

    for nxt in adj[cur_vertex]:
        cost, nxt_vertex = nxt
        if d[nxt_vertex] > d[cur_vertex] + cost:
            d[nxt_vertex] = d[cur_vertex] + cost
            heapq.heappush(pq, (d[nxt_vertex], nxt_vertex))

for i in range(1, v+1):
    if d[i] == INF:
        print("INF")
    else:
        print(d[i])
