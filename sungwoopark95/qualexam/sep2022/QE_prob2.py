class GNode:
    def __init__(self, id):
        self.id = id
    
    def __str__(self):
        return self.id    

def paths(G:dict, s:GNode, t:GNode):
    all_paths = []
    def dfs(G:dict, src:GNode, dst:GNode, path:list) -> None:
        print(f"source: {src.id}, destination: {dst.id}")
        if src.id == dst.id:
            all_paths.append(path[:])
        else:
            for node in G[src]:
                print(f"visited: {node.id}")
                path.append(node.id)
                print(f"path: {path}")
                dfs(G, node, dst, path)
                path.pop()
    dfs(G, s, t, path=[s.id])
    return all_paths

if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]
    
    # print(paths(G, a, c))
    # print(G)
    # print(paths(G, a, c))
    paths(G, a, c)
