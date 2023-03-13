from typing import List

# Node definition.
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node 
        self.distance = d
        self.parent = p

    def __str__(self):
        return self.id
    

def bfs(G: dict, s: GNode):

    if s not in G.keys():
        G[s] = []
        for k, v in G.items():
            
            if s in v:
                G[s].append(k)

    q = []
    s.color = "G"
    q.append(s)

    while q:
        curNode = q.pop(0)

        for v in G[curNode]:
            
            if v.color == "W":
                v.color = "G"
                v.distance = curNode.distance + 1
                v.parent = curNode
                q.append(v)

        curNode.color = "B"

    return
    
# def level_partition(G, s) -> List:

#     bfs(G, s)

#     max_dist = 0
#     for k in G:

#         if k.distance > max_dist:
#             max_dist = k.distance

#     ans = [[] for _ in range(max_dist+1)]

#     for k in G:
#         ans[k.distance].append(k.id)    

#     return ans


def level_partition(G, s):
    # perform BFS to get distance and parent information
    bfs(G, s)

    # partition nodes by level
    partitions = []
    max_level = max(node.distance for node in G)
    for level in range(max_level + 1):
        partition = []
        for k, v in G.items():
            nodes = [k]
            nodes.extend(v)
            for node in nodes:
                if node.id not in partition and node.distance == level:
                    partition.append(node.id)

        partitions.append(partition)

    return partitions

if __name__ == '__main__':
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[w], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

    result = level_partition(G, s)
    print(result)