# 2022_03_Qualification_Exam Q2
from typing import List
from collections import deque


class GNode:
    max_distance = 0

    def __init__(self, idx, color="W", d=0, p=None):
        self.idx = idx  # id is a string
        self.color = color  # color (status) of node
        self.distance = d
        self.parent = p

    def __str__(self):
        return self.idx


def bfs(graph, start: GNode):
    ans = [[]]
    q = deque()
    start.color = "B"  # if Black else
    start.distance = 0
    q.append(start)
    while q:
        curr_node = q.popleft()
        if len(ans) - 1 < curr_node.distance:
            ans.append([])
            ans[-1].append(curr_node.idx)
        else:
            ans[curr_node.distance].append(curr_node.idx)
        for next_node in graph[curr_node]:
            if next_node.color == "W":
                next_node.color = "B"
                next_node.distance = curr_node.distance + 1
                next_node.parent = curr_node
                GNode.max_distance = max(GNode.max_distance, curr_node.distance + 1)
                q.append(next_node)
    return ans


def level_partition(graph, start: GNode) -> List[List[GNode]]:
    ans = bfs(graph, start)
    return ans


if __name__ == "__main__":
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]
    print(level_partition(G, s))



