from collections import deque
import sys
input = sys.stdin.readline

v, e = map(int, input().split())
adj = [[] for _ in range(v+1)]
vis = [0 for _ in range(v+1)]

for _ in range(e):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
num = 0
for i in range(1, v+1):
    if(vis[i]): continue
    vis[i] = 1
    num += 1
    q = deque()
    q.append(i)
    while q:
        cur = q.popleft()
        for n in adj[cur]:
            if (vis[n]): continue
            vis[n] = 1
            q.append(n)

print(num)