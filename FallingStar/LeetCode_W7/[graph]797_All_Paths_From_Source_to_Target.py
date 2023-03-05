from typing import List
from collections import deque


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        curr = 0
        q = deque([[curr]])
        while q:
            tmp = q.popleft()
            last_node = tmp[-1]
            for next_node in graph[last_node]:
                if next_node not in tmp:
                    if next_node == len(graph) - 1:
                        ans.append(tmp+[next_node])
                    else:
                        q.append(tmp+[next_node])
        return ans
