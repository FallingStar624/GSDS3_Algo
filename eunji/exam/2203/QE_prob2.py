class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id

def bfs(G, s):
    q = [s]
    while q:
        node = q.pop(0) # r, w, v, t, x
        node.color = "B"
        if node.parent:
            # print(node.id)
            # print(node.parent.id, node.parent.distance)
            node.distance = node.parent.distance + 1
        for child in G[node]:
            if child.color == "W":
                child.color = "B"
                child.parent = node
                q.append(child)

def level_partition(G, s):
    if s == None:
        return []
    bfs(G, s)
    nodes_per_level = {}
    for node in G.keys():
        if node.distance in nodes_per_level:
            # nodes_per_level[node.distance].extend([node.id])
            nodes_per_level[node.distance].extend([node])
        else:
            # nodes_per_level[node.distance] = [node.id]
            nodes_per_level[node.distance] = [node]
    nodes_per_level = sorted(nodes_per_level.items())
    ans = [nodes for level, nodes in nodes_per_level]
    # print(ans)
    return ans
    
if __name__ == '__main__':
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]
    level_partition(G, s)