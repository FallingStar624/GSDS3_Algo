# [Backtracking] 797 All Paths From Source to Target와 유사한 문제
from typing import List
class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id

def paths(G, s, t) -> List:
    result = []
    def backtrack(curr, path):
        if str(curr) == str(t):
            result.append(list(path))
            return
        # print(curr)
        for next in G[curr]:
            path.append(str(next))
            backtrack(next, path)
            path.pop()
    path = [str(s)]
    backtrack(s, path)

    return result