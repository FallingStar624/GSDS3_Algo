class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    
    def __str__(self):
        return self.id


def bfs(G, s):
    ## level of a tree is determined by the distance from the source node
    ## level 0 -> source node / level 1 -> children of the source node / level 2 -> ...
    ## first, define the queue to be used for BFS
    ans = [] # container of the nodes in each level -> [[s], [r, w], [v, t, x], [u, y]]
    q = [s]
    s.color = "B" # check if visited
    while q:
        curr = q.pop(0)
        if len(ans) <= curr.distance:
            ## first node at a new level
            ans.append([curr.id])
        else:
            ## another node at the same level
            ans[curr.distance].append(curr.id)
        for child in G[curr]:
            if child.color == "B": continue
            child.color = "B"
            child.distance = curr.distance + 1
            q.append(child)
    return ans

def level_partition(G, s):
    return bfs(G, s)


if __name__ == "__main__":
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]
    
    print(level_partition(G, s))
