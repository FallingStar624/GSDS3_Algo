class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # directed acyclic graph with n nodes
        # each element means edges
        
        node = len(graph)
        # visit = [[0 for j in range(col)] for i in range(row)]
        res = []
        if node==0:
            return [[]]
        
        def dfs(num):
            if num == node-1:
                res.append([num -1])
            
            
            for i in graph[num]:
                for path in dfs(i):
                    if path:
                        res.append([num]+path)
            return res
        
        return dfs(0)