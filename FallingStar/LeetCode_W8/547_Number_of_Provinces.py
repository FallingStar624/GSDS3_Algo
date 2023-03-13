from collections import deque


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        ans = 0
        total = len(isConnected)
        visited = [False for _ in range(total)]
        for i in range(total):
            if not visited[i]:
                ans += 1
                visited[i] = True
                q = deque([i])
                while q:
                    curr_city = q.popleft()
                    for adj_city in range(total):
                        if isConnected[curr_city][adj_city] and not visited[adj_city]:
                            visited[adj_city] = True
                            q.append(adj_city)
            else:
                continue
        return ans
    
