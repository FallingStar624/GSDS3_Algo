from typing import List
from collections import deque, defaultdict


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if n-1 > len(connections):
            return -1
        num_nets = 0
        surplus = 0
        adj_lst = defaultdict(set)
        visited = [False for _ in range(n)]
        for connection in connections:
            a, b = connection
            adj_lst[a].add(b)
            adj_lst[b].add(a)
        for i in range(n):
            if not visited[i]:
                num_nets += 1
                num_nodes = 1
                num_connects = 0
                visited[i] = True
                q = deque([i])
                while q:
                    curr_city = q.popleft()
                    for adj_city in adj_lst[curr_city]:
                        num_connects += 1
                        if not visited[adj_city]:
                            num_nodes += 1
                            visited[adj_city] = True
                            q.append(adj_city)
                surplus += num_connects//2 - num_nodes + 1
            else:
                continue
        if surplus >= num_nets-1:
            return num_nets - 1
        else:
            return -1


