import sys
import heapq
input = sys.stdin.readline
v = int(input())
e = int(input())
adj = [[] for _ in range(v+1)]
INF = float('inf')
d = [INF] * (v+1)
pre = [0] * (v+1)

for _ in range(e):
    a, b, w = map(int, input().split())
    adj[a].append((w, b))

st, en = map(int, input().split())

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
            pre[nxt_vertex] = cur_vertex

print(d[en])
path = []
cur = en
while cur != st:
    path.append(cur)
    cur = pre[cur]
path.append(cur)
path.reverse()

print(len(path))
print(' '.join(map(str, path)))
