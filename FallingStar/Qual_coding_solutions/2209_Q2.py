# 2022_09_Qualification_Exam Q2
from typing import List
from collections import deque


class GNode:
    def __init__(self, idx):
        self.idx = idx

    def __str__(self):
        return self.idx


def paths(graph: dict[List], s: GNode, t: GNode) -> List[List[str]]:
    ans = []
    q = deque()
    q.append([s])
    while q:
        curr = q.popleft()
        last_node = curr[-1]
        for next_candidate in graph[last_node]:
            if next_candidate not in curr:
                if next_candidate == t:
                    ans.append(curr+[next_candidate])
                else:
                    q.append(curr+[next_candidate])
    for i, tmp in enumerate(ans):
        ans[i] = [x.idx for x in tmp]
    return ans


if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]
    print(paths(G, a, c))




