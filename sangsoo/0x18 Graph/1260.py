from collections import deque
import sys
input = sys.stdin.readline

vis1 = [0 for _ in range(1001)]
vis2 = [0 for _ in range(1001)]
adj = [[] for _ in range(1001)]
def bfs(v:int)->None:
    q = deque()
    q.append(v)
    vis1[v] = 1
    while q:
        cur = q.popleft()
        print(cur, end = ' ')
        for nxt in adj[cur]:
            if(vis1[nxt]): continue
            vis1[nxt] = 1
            q.append(nxt)

def dfs1(v:int)->None:
    s = deque()
    s.append(v)
    while(s):
        cur = s.pop()
        if(vis2[cur]): continue
        vis2[cur] = 1
        print(cur, end = ' ')
        for i in range(len(adj[cur])):
            nxt = adj[cur][len(adj[cur])-1-i]
            if(vis2[nxt]): continue
            s.append(nxt)

def dfs2(v:int) -> None:
    vis2[v] = 1
    print(v, end = ' ')
    for nxt in adj[v]:
        if (vis2[nxt]): continue
        dfs2(nxt)

# n : 노드 개수, m : edge 개수, v : 시작노드 
n, m, v = map(int, input().split())
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

for i in range(1, (n+1)): # n개까지 정렬!
    adj[i].sort()

dfs1(v)
print("")
bfs(v)