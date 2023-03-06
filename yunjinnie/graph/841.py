class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        # n rooms, all locked except for 0
        # visit with key
        # 0 -> 1, 1-> 2, 2-> 3, 3
        
        n = len(rooms)
        
        #visit = [0] for i in range(len(rooms))
        visit = [0]*n
        
        def dfs(room):
            if visit[room]:
                return
            visit[room] = 1
            for r in rooms[room]:
                if not visit[r]:
                    dfs(r)
        
        dfs(0)
        if False in visit:
            return False
        
        return True
    
# https://one10004.tistory.com/100