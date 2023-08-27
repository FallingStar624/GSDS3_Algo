from collections import deque

def bfs(start):
    queue = deque([start])
    vis[start] = 1
    while queue:
        cur = queue.popleft()
        for nxt in adj[cur]:
            if vis[nxt]:
                continue
            vis[nxt] = 1
            par[nxt] = cur
            queue.append(nxt)
def dfs(v):
    vis[v] = 1
    for nxt in adj[v]:
        if vis[nxt]:
            continue
        par[nxt] = v
        dfs(nxt)
        
n = int(input())
adj = [[] for _ in range(n + 1)]
par = [0] * (n + 1)
vis = [0] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, input().strip().split())
    adj[a].append(b)
    adj[b].append(a)

bfs(1)
for i in range(2, n + 1):
    print(par[i])
