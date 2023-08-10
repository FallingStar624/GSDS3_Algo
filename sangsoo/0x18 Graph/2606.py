import sys
from collections import deque
input = sys.stdin.readline

adj = [[] for _ in range(101)]
vis = [0 for _ in range(101)]

def bfs(v : int) -> int:
    q = deque()
    q.append(v)
    vis[v] = 1
    cnt = 0
    while q:
        cur = q.popleft()
        for nxt in adj[cur]:
            if(vis[nxt]): continue
            vis[nxt] = 1
            cnt += 1
            q.append(nxt)
    return cnt

n = int(input())
m = int(input())

for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

print(bfs(1))