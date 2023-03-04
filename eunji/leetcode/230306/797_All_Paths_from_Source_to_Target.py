from typing import List

class Solution:
    def dfs(self, graph, visited, paths, curr):
        paths.append([curr])
        for child in graph[curr]:
            if child not in visited:
                visited.append(child)
                self.dfs(graph, visited, paths, child)
        return ans 
    
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        visited = []
        paths = []
        return self.dfs(self, graph, visited, paths, 0)