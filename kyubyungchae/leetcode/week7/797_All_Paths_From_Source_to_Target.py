from typing import List
from collections import deque

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        q = deque()

        q.append((0, [0]))
        result = []

        while q:
            node, path = q.popleft()

            if node == len(graph) - 1:
                result.append(path)

            for next_node in graph[node]:
                q.append((next_node, path + [next_node]))

        return result
    
if __name__ == '__main__':
    sol = Solution()
    graph = [[1,2],[3],[3],[]]
    print(sol.allPathsSourceTarget(graph))
