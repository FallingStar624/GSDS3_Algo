class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
        self.visit = False
        
    def __str__(self):
        return self.id

    
def bfs(G, s):
    # visit initialization
    for key in G.keys():
        key.visit = False
        
    q = []
    q.append(s)
    s.parent = None
    s.distance = 0
    while q:
        cur = q.pop(0)
        print(cur)
#         print(f"cur id   : {cur.id} | cur distance   : {cur.distance}")
        cur.visit = True
        for child in G[cur]:
            # visit check
            if child.visit == True:
                continue
            child.parent = cur # parent
            child.distance = cur.distance + 1 # distance
#             print(f"child id : {child.id} | child distance : {child.distance} | child parent : {child.parent}")
            child.visit = True
            q.append(child)
        
                
def level_partition(G, s):
    """
    [s]
    [r, w]
    [v, t, x]
    ...
    """
    # BFS without print function
    # visit initialization
    for key in G.keys():
        key.visit = False
        
    q = []
    q.append(s)
    s.parent = None
    s.distance = 0
    max_distance = -1
    while q:
        cur = q.pop(0)
#         print(cur)
#         print(f"cur id   : {cur.id} | cur distance   : {cur.distance}")
        cur.visit = True
        if max_distance < cur.distance:
            max_distance = cur.distance
        for child in G[cur]:
            # visit check
            if child.visit == True:
                continue
            child.parent = cur # parent
            child.distance = cur.distance + 1 # distance
#             print(f"child id : {child.id} | child distance : {child.distance} | child parent : {child.parent}")
            child.visit = True
            q.append(child)
        
    
    levels = [ [] for _ in range(max_distance+1) ]
    for node in G.keys():
        cur_distance = node.distance
        levels[cur_distance].append(node)
    return levels
        
        
        
            
            
    