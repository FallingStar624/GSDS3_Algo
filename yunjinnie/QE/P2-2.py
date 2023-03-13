class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id
    
def paths(G, s, t):
    # dfs & backtracking
    ans = []
    visit = []
    visit.append(s)

    def dfs(adj, s, t, path):
        if s==t:
            ans.append(path)
        #while path:
        else:
            for node in adj[s]:
                #node = path.pop()
                #if node not in visit:
                #    visit.append(node)
                #path.extend(G[node])
                path.append(node)
                dfs(adj, node, t, path)
                path.pop()

    dfs(G, s, t, visit)
    for path in visit:
        ans.append(str(path))
    
    return ans

a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
G = dict()
G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]
print(paths(G, a, c))