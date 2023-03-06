from typing import List

class Solution:
    def __init__(self):
        self.ans = False

    def dfs(self, rooms, visited, curr):
        if len(visited) == len(rooms):
            self.ans = True
        
        for key in rooms[curr]:
            if key not in visited:
                visited.add(key)    
                self.dfs(rooms, visited, key)      
        
        
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set([0])
        self.dfs(rooms, visited, 0)      
        return self.ans
    
if __name__ == '__main__':
    S = Solution()
    graph = [[1],[2],[3],[]]
    A = S.canVisitAllRooms(graph)
    print(A)