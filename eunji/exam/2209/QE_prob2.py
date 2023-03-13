class GNode:
    def __init__(self, id):
        self.id = id
        # self.visited = False
        
    def __str__(self):
        return self.id

class Solution():
    def __init__(self, start):
        self.ans = []
        self.visited = [start.id]
        self.start = start
        
    def reset(self):
        self.visited = [self.start.id]
        
    def dfs(self, G, curr, target):
        if curr.id == target.id:
            self.ans.append(self.visited)
            self.reset() 
            return
        
        for neighbor in G[curr]:
            if (neighbor.id not in self.visited):
                self.visited.append(neighbor.id)
                self.dfs(G, neighbor, target)
        
def paths(G, a, c):
    S = Solution(a)
    S.dfs(G, a, c)
    return S.ans
              
if __name__ == '__main__':
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b,c], [d], [], [c]
    A = paths(G, a, c)
    print(A)