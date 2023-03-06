class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.graph = graph
        self.n = len(graph)
        self.ret = []
        self.v = [0 for _ in range(self.n)]
        self.v[0] = 1
        self.dfs(0, [0])
        return self.ret
    
    def dfs(self, cn, path):
        if cn == self.n - 1:
            self.ret.append(path)
            return
        if len(path) >= self.n:
            return
        
        path = copy.deepcopy(path)
        for nn in self.graph[cn]:
            if self.v[nn]:
                continue
            self.v[nn] = 1
            path.append(nn)
            self.dfs(nn, path)
            path = path[:-1]
            self.v[nn] = 0