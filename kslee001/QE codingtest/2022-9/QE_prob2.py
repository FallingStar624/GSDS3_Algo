class GNode:
    def __init__(self, id):
        self.id = id
        self.dist  = 0
        self.previous = []
    
    def __str__(self):
        return self.id


def paths(G, s, t): # all paths between node s and node t 
    
    # initialization
    for node in G.keys():
        node.dist = 0
    
    res = []
    
    # BFS without print
    max_length = -1
    q = []
    q.append(s)
    s.previous.append(s.id)

    while q:
        cur = q.pop(0)
        if cur.dist > max_length:
            max_length = cur.dist
        for child in G[cur]:
            if child.id == t.id:
                res.append(cur.previous + [child.id])
                continue
            if child.dist:
                continue
            child.dist = cur.dist + 1
            child.previous = cur.previous + [child.id]
            q.append(child)
    
    return res