from collections import defaultdict

class Solution:
    def __init__(self):
        self.measure = []
        self.jug1Capacity = 0
        self.jug2Capacity = 0
        self.targetCapacity = 0
        self.visited = set()
        self.ans = False

    def dfs(self, w1, w2):
        if self.ans:
            return
        if w1 < 0 or w2 < 0:
            return
        if (w1, w2) in self.visited:
            return
        else:
            self.visited.add((w1, w2))
        if w1 == self.targetCapacity or w2 == self.targetCapacity:
            self.ans = True
            return
        if w1+w2 == self.targetCapacity:
            self.ans = True
            return
        else:
            n_steps = [(w1, 0), (0, w2),
                       (0, min(w1, self.jug2Capacity)), (min(w2, self.jug1Capacity), 0),
                       (self.jug1Capacity, w2), (w1, self.jug2Capacity),
                       (w1-(self.jug2Capacity-w2), self.jug2Capacity), (self.jug1Capacity, w2-(self.jug1Capacity-w1)),
                       ]
            for nw1, nw2 in n_steps:
                if (nw1, nw2) not in self.visited and nw1 >= 0 and nw2 >= 0:
                    self.dfs(nw1, nw2)

    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        self.measure = [False for _ in range(targetCapacity)]
        self.jug1Capacity = jug1Capacity
        self.jug2Capacity = jug2Capacity
        self.targetCapacity = targetCapacity
        self.dfs(0, 0)
        return self.ans

