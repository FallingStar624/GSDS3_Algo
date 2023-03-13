class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node 
        self.distance = d
        self.parent = p

    def __str__(self):
        return self.id



def paths(G, s, t):
    paths_= []
    path = []

    def dfs(G, s, t, p=[]):
    
        p.append(s.id)
        if s == t:
            paths_.append(p)
        else:
            for v in G[s]:
                if v.id not in p:
                    dfs(G, v, t, p.copy())

    dfs(G, s, t, path)
    return paths_
    

if __name__ == '__main__':

    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')

    G = dict()
    G[a], G[b], G[c], G[d] = [c, b], [d], [], [c]
    result = paths(G, a, c)
    print(result)
    # r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    # w, x, y = GNode('w'), GNode('x'), GNode('y')
    # G = dict()
    # G[s] = [r, w]
    # G[r], G[w], G[t], G[u], G[v] = [v], [t, x], [x, u], [x, y], []
    # G[w], G[x], G[y] = [t, x], [y], []
    # print(paths(G, s, y))