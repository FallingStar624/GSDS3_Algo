from typing import List
from collections import deque, defaultdict


class Solution:
    def __init__(self):
        self.max_time = 0

    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        sub_list = defaultdict(list)
        for idx, m in enumerate(manager):
            sub_list[m].append(idx)
        q = deque([(headID, 0)])
        while q:
            curr = q.popleft()
            self.max_time = max(curr[1], self.max_time)
            for sub in sub_list[curr[0]]:
                q.append((sub, curr[1]+informTime[curr[0]]))
        return self.max_time

