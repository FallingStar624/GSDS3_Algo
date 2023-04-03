class GNode:
    def __init__(self, id):
        self.id = id
        # add
    def __str__(self):
        return self.id
    
def paths(G, s, t):
    # dfs & backtracking -> 797 (Graph: list[list])
    # next： occupied, 함수 이름 겹치는 것도 x
    # p.copy() -> shallow, 안하면 마지막 path만 계속 출력됨

    ans = []
    #visit = [] # no cycle
    visit = {i: 0 for i in G.keys()} # path appended
    #visit.append(s)
    visit[s]=True
    #print(visit) : 4 objects 

    def dfs(s, t, path):
        if s==t: # end
            ans.append(path)
            return
            
        else:
            for node in G[s]:
                # s -> visited
                # G[s] -> not visited
                if visit[node]:
                    continue

                # if node in visit: # already added
                #     print(str(node))
                # != if visit[node]:

                # if node not in visit:
                #     visit.append(node)
                #     continue # skip

                visit[node]=True
                #visit.append(node)
                #node = path.pop()
                #path.extend(G[node])

                dfs(node, t, path+[str(node)])
                visit[node]=False

    dfs(s, t, [str(s)])
    # for path in visit:
    #     ans.append(str(path))
    
    return ans

a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
G = dict()
G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]
print(paths(G, a, c))

# m과 n