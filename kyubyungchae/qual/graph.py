

class undi_graph():
    def __init__(self, V: list, E: list) -> None:
        self.V = V[:] 
        self.neighbor = {} 
        for v in V:
            self.neighbor[v] = [] 
        for (v, w) in E:
            self.neighbor[v].append(w) 
            self.neighbor[w].append(v)

    def __str__(self) -> str:
        
        return str(self.neighbor)
    
    def DFT(self) -> None:
        if self.V:
            visited = {}
            for v in self.V:
                visited[v] = False
            for v in self.V:
                self.__DFTHelp(visited, v)
        print()

    def __DFTHelp(self, visited: list, v: int) -> None:
        if not visited[v]:
            visited[v] = True
            # print(v, end=' ') # Preorder
            idx = 0
            for w in self.neighbor[v]:
                self.__DFTHelp(visited, w)
                
            print(v, end=' ') # Postorder

if __name__ == '__main__':

    V = [i for i in range(0, 10)]
    E = [(0, 1), (1,4), (1,5), (4,6), (5,6),(6,9), (5,7), (7,8), (2,3)]

    G = undi_graph(V, E)

    print(G)

    G.DFT()
