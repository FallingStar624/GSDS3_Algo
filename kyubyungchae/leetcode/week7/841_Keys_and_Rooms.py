from typing import List
from collections import deque

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:

        q = deque()
        visited = [0 for _ in range(len(rooms))]
        q.append((0, rooms[0]))
        visited[0] = 1

        while q:
            room, key = q.popleft()

            for next_room in key:
                if visited[next_room] == 0:
                    visited[next_room] = 1
                    q.append((next_room, rooms[next_room]))

        return sum(visited) == len(rooms)
    

if __name__ == '__main__':
    sol = Solution()
    # rooms = [[1],[2],[3],[]]
    # rooms = [[1,3],[3,0,1],[2],[0]]
    rooms = [[2],[],[1]]
    print(sol.canVisitAllRooms(rooms))
