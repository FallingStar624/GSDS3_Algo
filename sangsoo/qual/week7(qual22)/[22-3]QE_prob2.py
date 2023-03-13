from collections import deque
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node W: unvisited nodes, B: visited nodes
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id

r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
G = dict()
G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

def bfs(G, node) -> None:
    # initialize
    for node in G:
        node.color = "W" # unvijsited

    q = deque([])
    q.append(node)
    d = 0
    node.color = "B" # visited
    node.distance = 0
    while q:
        v = q.popleft()
        for w in G[v]:
            if w.color == "W":
                w.color = "B"
                q.append(w)
                w.distance = v.distance+1
                print(f"visit {w} node!")

def level_partition(G, node) -> None: # node로 return
    # initialize
    for node in G:
        node.color = "W"
        
    q = deque([])
    q.append(node)
    d = 0
    out = [[] for _ in range(len(G))] # [0]*len(G) 
    node.color = "B"
    node.distance = 0
    out[0] = [node]
    # print(out)
    while q:
        v = q.popleft()
        for w in G[v]:
            if w.color == "W":
                w.color = "B"
                q.append(w)
                w.distance = v.distance+1
                out[w.distance].append(w)
    outlist = []
    for i in range(len(G)):
        if out[i]:
            outlist.append(out[i])

    return outlist

def level_partition_str_ver(G, node) -> None: # str로 리턴턴
    # initialize
    for node in G:
        node.color = "W" # unvijsited
        
    q = deque([])
    q.append(node)
    d = 0
    out = [[] for _ in range(len(G))] # [0]*len(G) 이런식으로 하면 alias가 생김 
    node.color = "B" # visited
    node.distance = 0
    out[0] = [str(node)]
    # print(out)
    while q:
        v = q.popleft()
        for w in G[v]:
            if w.color == "W":
                w.color = "B"
                q.append(w)
                w.distance = v.distance+1
                out[w.distance].append(str(w))
    outlist = []
    for i in range(len(G)):
        if out[i]:
            outlist.append(out[i])

    return outlist