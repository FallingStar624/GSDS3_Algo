import heapq

def prim(graph, start):
    mst = []
    visited = [False] * len(graph)
    edges = [(0, start)]
    while edges:
        weight, node = heapq.heappop(edges)
        if not visited[node]:
            visited[node] = True
            mst.append((weight, node))
            for w, adj_node in graph[node]:
                if not visited[adj_node]:
                    heapq.heappush(edges, (w, adj_node))
    return mst

v, e = map(int, input().split())
graph = [[] for _ in range(v+1)]

for _ in range(e):
    a, b, cost = map(int, input().split())
    graph[a].append((cost, b))
    graph[b].append((cost, a))

mst = prim(graph, 1)
ans = sum([weight for weight, _ in mst])

print(ans)