from collections import deque

class Solution:
    def __init__(self):
        self.visited = set()
        self.total = 0
        self.ans = False

    def checkCond(self, num):
        if -1 < num <self.total and num not in self.visited:
            return True
        return False

    def canReach(self, arr: List[int], start: int) -> bool:
        self.total = len(arr)
        q = deque([start])
        while q:
            curr = q.popleft()
            if arr[curr] == 0:
                self.ans = True
                break
            if self.checkCond(curr):
                self.visited.add(curr)
                if self.checkCond(curr+arr[curr]):
                    q.append(curr+arr[curr])
                if self.checkCond(curr-arr[curr]):
                    q.append(curr-arr[curr])
        print(self.visited)
        return self.ans
