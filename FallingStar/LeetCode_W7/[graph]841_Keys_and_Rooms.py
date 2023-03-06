from typing import List
from collections import deque


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        total = len(rooms)
        visited = [False for _ in range(total)]
        q = deque()
        q.append(0)
        visited[0] = True
        while q:
            curr = q.popleft()
            keys = rooms[curr]
            for key in keys:
                if not visited[key]:
                    visited[key] = True
                    q.append(key)
        if sum(visited) < total:
            return False
        return True


