def func(mat):
    Y = len(mat)
    X = len(mat[0])
    G = mat
    V = [[0 for __ in range(X)] for _ in range(Y)]
    result = [[0 for __ in range(X)] for _ in range(Y)]
    
    dy = [1,0,-1,0]
    dx = [0,1,0,-1]

    # collect coordinates of lands
    queue = []
    for y in range(Y):
        for x in range(X):
            if G[y][x] == 1:
                queue.append((y,x))

    while queue:
        y, x = queue.pop(0)
        flag = False # 주변부에 물이 있는지?
        V[y][x] = True
        dist = 0
        
        # bfs for "LAND"
        for d in range(4):
            ny, nx = y+dy[d], x+dx[d]
            
            
            # oob
            if(ny<0)|(nx<0)|(ny>=Y)|(nx>=X):
                continue
            # visit
            if(V[ny][nx]!=0):
                continue    
            # 현재 보고 있는 주변부에 물이 있는 경우
            if(G[ny][nx]==0):
                flag = True
                result[y][x] = 1
                continue
            # 현재 보고 있는 주변부가 땅인 경우
            else:
                queue.append((ny, nx))
        
        if not flag:
            min_distance = 999999999999
            for d in range(4):
                if (ny<0)|(nx<0)|(ny>=Y)|(nx>=X):
                    continue
                if result[ny][nx] < min_distance:
                    min_distance = result[ny][nx]
            result[y][x] = min_distance + 1
            
        
#     for y in range(Y):
#         for x in range(X):
#             if result[y][x] > 100000000:
#                 result[y][x] = 0
    
    
    return result
            
            
            
        
    
