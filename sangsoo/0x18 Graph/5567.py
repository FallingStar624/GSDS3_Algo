from collections import deque
import sys
input = sys.stdin.readline

adj = [[] for _ in range(502)]
vis = [0 for _ in range(502)]
lv = [0 for _ in range(502)]

def bfs(v: int, mx_lv: int)->int: #v: 시작노드(이문제에서는 1), mx_lv : 최대 lv(이문제에서는 2)
    cnt = 0
    q = deque()
    q.append(v)
    vis[v] = 1
    lv[v] = 0
    while(q):
        cur = q.popleft()
        for nxt in adj[cur]:
            if (vis[nxt]): continue
            if (lv[cur] == mx_lv): return cnt
            vis[nxt] = 1; cnt+=1
            q.append(nxt)
            lv[nxt] = lv[cur] + 1
    return cnt

n = int(input())
m = int(input())
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

print(bfs(1, 2))