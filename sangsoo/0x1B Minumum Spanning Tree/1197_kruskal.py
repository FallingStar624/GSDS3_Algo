import sys
input = sys.stdin.readline
def find(x, parent):
    if parent[x] < 0:
        return x
    parent[x] = find(parent[x], parent)
    return parent[x]

def is_diff_group(u, v, parent):
    u = find(u, parent)
    v = find(v, parent)

    if u == v:
        return False

    if parent[u] == parent[v]:
        parent[u] -= 1
    if parent[u] < parent[v]:
        parent[v] = u
    else:
        parent[u] = v

    return True

v, e = map(int, input().split())
edges = []
for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

parent = [-1] * (v+1)
cnt = 0
ans = 0
for edge in edges:
    cost, a, b = edge
    if not is_diff_group(a, b, parent):
        continue
    ans += cost
    cnt += 1
    if cnt == v-1:
        break

print(ans)

