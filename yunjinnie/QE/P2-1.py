from collections import deque
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id

def bfs(G, s):
    q = deque()
    visit = [0 for i in range(len())]
    level = [0 for i in range(len())]

    visit[s] = 1
    q.append(s)
    # level[s] = 0

    while q:
        x = q.popleft()
        for i in range(len(G[x])):
            if not visit[i]:
                level[i] = level[s]+1
                visit[i]=1
                q.append(i)

    ans = []
    for i in range():
        if level[i]==1:
            ans.append(i)

    return ans

def level_partition(G, s):
    ans = []

    for i in G:
        ans = bfs(i, s)

    return ans

r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
G = dict()

G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

level_partition(G, s)