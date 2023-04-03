from collections import deque # xx

class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id
# update

def bfs(G, s):
    q = deque()
    #visit = [] # color
    visit = {i: 0 for i in G.keys()} # for dict
    #level = [0 for i in range(len())] -> distance
    ans = []

    visit[s] = 1
    q.append(s)

    while q:
        x = q.pop() # popleft
        if len(ans)<=x.distance:
            ans.append([x.id])
            
        else:
            ans[x.distance].append(x.id)

        for node in G[x]:
            if visit[node]:
                continue

            #level[node] = level[s]+1
            node.distance = x.distance+1
            visit[node]=1
            q.append(node)
            # bfs -> visit = 0 xxx

    return ans

def level_partition(G, s):
    if not s:
        return None
    
    ans = bfs(G, s)

    return ans

r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
G = dict()

G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

print(level_partition(G, s))

# 객체, not string -> 주의할 것
# if __name__ == "__main__": 있어야 함
# visit order check