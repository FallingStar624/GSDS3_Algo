from collections import deque

adj = [[] for _ in range(10)]
vis = [0 for _ in range(10)]

# BFS 연결 그래프에서 순회, 시작 노드 v
def bfs_traverse(v:int)->None:
    q = deque()
    q.append(v)
    vis[v] = 1
    while(q):
        cur = q.popleft()
        print(cur, end = ' ')
        for nxt in adj[cur]:
            if(vis[nxt]): continue
            vis[nxt] = 1
            q.append(nxt)

# BFS 연결그래프에서 v번 노드와 정점과의 거리

dist = [-1 for _ in range(10)]
def bfs_dist(v: int)->None:
    q = deque()
    q.append(v)
    dist[v] = 0
    while(q):
        cur = q.popleft()
        for nxt in adj[cur]:
            if(dist[nxt] != -1): continue
            q.append(nxt)
            dist[nxt] = dist[cur]+1

# BFS 연결 그래프가 아닐 때 순회
adj = [[] for _ in range(10)]
vis = [0 for _ in range(10)]
v = 9 # 정점의 수

def bfs_traverse2():
    q = deque()
    for i in range(1, 10):
        if (vis[iW]): continue
        q.append(i)
        vis[i] = 1
        while(q):
            cur = q.popleft()
            print(cur, end = ' ')
            for nxt in adj[cur]:
                if(vis[cur]): continue
                q.append(nxt)
                vis[nxt] = 1

# DFS 연결 그래프에서 순회, 비재귀 (재귀와 같게 출력)
adj = [[] for _ in range(10)]
vis = [0 for _ in range(10)]

def dfs(v:int)->None: 
    s = deque()
    s.append(v)
    while(s):
        cur = s.pop()
        if(vis[cur]): continue
        vis[cur] = 1
        print(cur, end = ' ')
        for i in range(len(adj[cur])):
            # 스택의 특성상 정점을 역순으로 넣어야함
            nxt = adj[cur][len(adj[cur])-1-i]
            if(vis[nxt]): continue
            s.append(nxt)

# DFS 연결 그래프에서 순회, 재귀
adj = [[] for _ in range(10)]
vis = [0 for _ in range(10)]

def dfs(v:int)->None:
    vis[v] =1
    print(v, end = ' ')
    for nxt in adj[v]:
        if (vis[nxt]): continue
        dfs(nxt)
