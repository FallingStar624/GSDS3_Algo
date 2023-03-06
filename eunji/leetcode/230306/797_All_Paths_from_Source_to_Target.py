from typing import List

class Solution:
    def __init__(self):
        self.paths = []

    def dfs(self, graph, path, curr, target):
        if curr == target:
            self.paths.append(path)
            return

        for child in graph[curr]:
            self.dfs(graph, path + [child], child, target)
    
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        path = [0]
        target = len(graph)-1
        self.dfs(graph, path, 0, target)
        return self.paths
    
if __name__ == '__main__':
    S = Solution()
    graph = [[2],[],[1]]
    A = S.allPathsSourceTarget(graph)
    print(A)