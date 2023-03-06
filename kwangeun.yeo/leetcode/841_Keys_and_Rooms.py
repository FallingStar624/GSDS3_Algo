class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        self.rooms = rooms
        self.n = len(rooms)
        self.v = [0 for _ in range(self.n)]
        self.ret = False
        self.keys = {0}
        self.v[0] = 1
        self.dfs(0, 1)
        return self.ret
    
    def dfs(self, room, L):
        if self.ret:
            return
        if len(self.keys) == self.n:
            self.ret = True
            return
                
        for nr in self.rooms[room]:
            if self.v[nr]:
                continue
            self.keys.add(nr)
            self.v[nr] = 1
            self.dfs(nr, L + 1)